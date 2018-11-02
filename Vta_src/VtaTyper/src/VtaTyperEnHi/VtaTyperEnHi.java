 package VtaTyperEnHi;

 import javax.swing.ImageIcon;
import edu.cmu.sphinx.frontend.util.Microphone;
import edu.cmu.sphinx.recognizer.Recognizer;
import edu.cmu.sphinx.result.Result;
import edu.cmu.sphinx.util.props.ConfigurationManager;
import edu.cmu.sphinx.util.props.ConfigurationManagerUtils;
import edu.cmu.sphinx.frontend.util.Microphone;
import edu.cmu.sphinx.recognizer.Recognizer;
import edu.cmu.sphinx.result.Result;
import edu.cmu.sphinx.util.props.PropertyException;
 
import java.util.LinkedList;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import java.io.File;
import java.util.Locale;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import javax.speech.Central;
import javax.speech.Engine;
import javax.speech.EngineList;
import javax.speech.EngineCreate;
import javax.speech.EngineException;
import javax.speech.EngineModeDesc;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.event.KeyEvent;
import java.util.logging.Level;
import java.util.logging.Logger;

 
  class Utils
{
	private static boolean mPrintDebug = false;
 
	static public void log(String msgType, String msg)
	{
		// If we're ignoring debug messages and this one is a debug 
		// message, return.
		if (!mPrintDebug && msgType.equals("debug"))
		{
			return;
		}

		String finalMessage = "[";

		if (!msgType.equals(""))
		{
			finalMessage = finalMessage + " " + msgType;
		}

		finalMessage =  msg  ;
                
		System.out.println(finalMessage);
		System.out.flush();
	}
 
	static public void setPrintDebug(boolean printDebug)
	{
		mPrintDebug = printDebug;
	}
}
 
   class SpeechInterface
{
	 private static SpeechRecognizer mRecognizer = null;

      public static void init( String grammarName,String Language,String lm)
	{
		Utils.setPrintDebug(false);
		Utils.log("debug", "Beginning initialization");
 
            String grammarPath = "";
			 
			String configFilename = "";
            if(Language.equals("Hi"))
			{   
     			grammarPath = "./lib/VtaSRGrammer/VtaGrammer_Hi";
				
				if(lm.equals(""))
				      lm = "VtaTyperEnHi_Hi_NoM.trigram.lm";
				
			     if (!grammarName.equals(""))
			    {
				   //  Utils.log("", "./lib/VtaTyperEnHiGrammer/VtaGrammer_Hi Hindi Grammer Loadeding");
			         configFilename = "VtaSR_Hi.config.xml";
				}
				else
				{    
				   configFilename = "VtaSR_Hi_NoM.config.xml";
				  // Utils.log("", "Default N Grammer Location   Loaded");
				}
			   
			 
			}
			else if(Language.equals("En"))
			{
			      grammarPath = "./lib/VtaSRGrammer/VtaGrammer_En";
				 
				 if(lm.equals(""))
				   lm = "VtaTyperEnHi_En_NoM.trigram.lm";
				  
				 if (!grammarName.equals(""))
			    {
				      configFilename = "VtaSR_En.config.xml";
				 }
				else
				{     
				     configFilename = "VtaSR_En_NoM.config.xml";
				}
			   
			}
			else
			{
			    
			}
			 
           //  Utils.log("", "Grammer "+ grammarName +" " + lm );
		//	 Utils.log("", "Initializing recognizer. " + "This may take some time...");
			// mRecognizer = new SpeechRecognizer(configFilename, grammarPath, grammarName);
          mRecognizer = new SpeechRecognizer("./lib/VtaSRLib/" + configFilename, grammarPath, grammarName,lm);
			 setRecognizerEnabled(true);
		 
	//	Utils.log("", "Initialization complete...");
	}

	/// Destroys Voce.	
	public static void destroy()
	{
		Utils.log("debug", "Shutting down...");
		
		 
		if (null != mRecognizer)
		{
			mRecognizer.destroy();
		}

		Utils.log("", "Shutdown complete");
	}

 
	public static int getRecognizerQueueSize()
	{
		if (null == mRecognizer)
		{
			Utils.log("warning", "getRecognizerQueueSize " + "called before recognizer was initialized.  Returning " + "0.");
			return 0;
		}

		return mRecognizer.getQueueSize();
	}
 
	public static String popRecognizedString()
	{
		if (null == mRecognizer)
		{
			Utils.log("warning", "popRecognizedString " + "called before recognizer was initialized.  Returning "  + "an empty string.");
			return "";
		}

		return mRecognizer.popString();
	}
 
	public static void setRecognizerEnabled(boolean e)
	{
		if (null == mRecognizer)
		{
			Utils.log("warning", "setRecognizerEnabled " + "called before recognizer was initialized.  Request "  + "will be ignored.");
			return;
		}

		mRecognizer.setEnabled(e);
	}
 
	public static boolean isRecognizerEnabled()
	{
		if (null == mRecognizer)
		{
			Utils.log("warning", "isRecognizerEnabled " + "called before recognizer was initialized.  Returning "  + "false.");
			return false;
		}	

		return mRecognizer.isEnabled();
	}
}

   class SpeechRecognizer implements Runnable
{
    private Recognizer mRecognizer = null;
    private Microphone mMicrophone = null;
    private volatile Thread mRecognitionThread = null;
 
	private boolean mRecognitionThreadEnabled = false;
    private LinkedList<String> mRecognizedStringQueue;
    
	public SpeechRecognizer(String configFilename, String grammarPath, String grammarName,String lm)
	{
		try
		{     URL configURL = new File(configFilename).toURI().toURL();
              ConfigurationManager cm = new ConfigurationManager(configURL);
		 	 
			mRecognizer = (Recognizer) cm.lookup("recognizer");
			mMicrophone = (Microphone) cm.lookup("microphone");
   
                if (!grammarName.equals(""))
			    {
				    ConfigurationManagerUtils.setProperty(cm,"jsgfGrammar", "grammarLocation", grammarPath);
		            ConfigurationManagerUtils.setProperty(cm,"jsgfGrammar", "grammarName", grammarName);
				}
				else
				{
				     ConfigurationManagerUtils.setProperty(cm,"trigramModel", "location", grammarPath+"/"+lm);
			    }
				 
              
			mRecognizer.allocate();
			mRecognizedStringQueue = new LinkedList<String>();
		}
		catch (IOException e)
        {
            Utils.log("ERROR", "Cannot load speech recognizer: ");
            e.printStackTrace();
        }
	    catch (PropertyException e)
		{
			Utils.log("ERROR", "Cannot configure speech recognizer: ");
			e.printStackTrace();
		}
		 
	}

	/// Contains the main processing to be done by the recognition 
	/// thread.  Called indirectly after 'start' is called.
	public void run()
	{
		Utils.log("debug", "Recognition thread starting");

		while (true == mRecognitionThreadEnabled)
		{
			if (!mMicrophone.isRecording())
			{
				Utils.log("warning", "Recognition thread is running, but " 
					+ "the microphone is disabled.");
			}
			else
			{
				Result result = mRecognizer.recognize();

				if (result != null)
				{
					String s = result.getBestFinalResultNoFiller();

					// Only save non-empty strings.
					if (!s.equals(""))
					{
					//	Utils.log("debug", "Finished recognizing");
						mRecognizedStringQueue.addLast(s);
					}
				}
			}
		}

		Utils.log("debug", "Recognition thread finished");
	}

	/// Returns the number of recognized strings currently in the 
	/// recognized string queue.
	public int getQueueSize()
	{
		return mRecognizedStringQueue.size();
	}

	/// Returns and removes the oldest recognized string from the 
	/// recognized string queue.  Returns an empty string if the 
	/// queue is empty.
	public String popString()
	{
		if (getQueueSize() > 0)
		{
			return mRecognizedStringQueue.removeFirst();
		}
		else
		{
			return "";
		}
	}

	/// Enables and disables the speech recognizer.  Starts and stops the 
	/// speech recognition thread.
	public void setEnabled(boolean e)
	{
		if (e)
		{
			Utils.log("debug", "Starting microphone...");
			boolean success = mMicrophone.startRecording();
			Utils.log("debug", "Microphone on");

			if (!success)
			{
				Utils.log("warning", "Cannot initialize microphone. " + 
					"Speech recognition disabled.");
				return;
			}
			else
			{
				if (null != mRecognitionThread)
				{
					Utils.log("warning", "New recognition thread being " 
						+ "created before the previous one finished.");
				}

				mRecognitionThread = new Thread(this, "Recognition thread");

				// Start running the recognition thread.
				mRecognitionThreadEnabled = true;
				mRecognitionThread.start();
			}
		}
		else
		{
			Utils.log("debug", "Stopping microphone...");
			mMicrophone.stopRecording();
			Utils.log("debug", "Microphone off");

			// The following line indirectly stops the recognition thread 
			// from running.  The next time the recognition thread checks 
			// this variable, it will stop running.
			mRecognitionThreadEnabled = false;

			// Wait for the thread to die before proceeding.
			while (mRecognitionThread.isAlive())
			{
				Utils.log("debug", "Waiting for recognition thread to die...");

				try
				{
					// Have the main thread sleep for a bit...
					Thread.sleep(100);
				}
				catch (InterruptedException exception)
				{
				}
			}

			mRecognitionThread = null;
			mMicrophone.clear();

			Utils.log("debug", "Clearing recognized string queue");
			mRecognizedStringQueue.clear();
		}
	}

	/// Returns true if the recognizer is currently enabled.
	public boolean isEnabled()
	{
		return mMicrophone.isRecording();
	}

	/// Deallocates speech recognizer.
	public void destroy()
	{
		// This function call will shut down everything, including the 
		// recognition thread.
		setEnabled(false);

		// It should now be safe to deallocate the recognizer.
		mRecognizer.deallocate();
	}
}

public class VtaTyperEnHi extends javax.swing.JFrame
{
    static String TypingLanguage;
    static String Loading;
    public VtaTyperEnHi() {
        initComponents();
    }
 
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowActivated(java.awt.event.WindowEvent evt) {
                formWindowActivated(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 0, 255));
        jLabel1.setText("Typing Can Not Started");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 300, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 44, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>                        
         class InitThread extends Thread {

          public InitThread() {
            super("Initt");
            }
              public void run() {
			  
			  while(true)
			  {
			     System.out.print("");
				  if(Loading.equals("Compleat"))
				{
                   if(TypingLanguage.equals("En"))
                   {
                           jLabel1.setText("English Typing Loading Compleate , Please Speak");
						   break;
                   }
                    else
                   {
                           jLabel1.setText("Hindi Typing Loading Compleate , Please Speak");
						     break;
                   }
               } 
			  }
			   
            }
        }
    private void formWindowActivated(java.awt.event.WindowEvent evt) {                                     
        // TODO add your handling code here:
		 ImageIcon img = new  ImageIcon("VtaIcon\\VtaBlue.png");
         this.setIconImage(img.getImage());
          this.setAlwaysOnTop(true);
           if(TypingLanguage.equals("En"))
            {
                  this.setTitle("English Voice Typing");
                  jLabel1.setText("English Typing Loading....");
            }
            else
            {
                     this.setTitle("Hindi Voice Typing");
                    jLabel1.setText("Hindi Typing Loading....");
            }
			
            (new InitThread()).start();
			 
          /*      if(Loading.equals("Compleat"))
			 	{
                   if(TypingLanguage.equals("En"))
                   {
                           jLabel1.setText("English Typing Loading compleate");
						 
                   }
                    else
                   {
                           jLabel1.setText("Hindi Typing Loading compleate");
						    
                   }
               }       */  
          
    }                                    
    
	public static void main(String[] argv)
	{
	
	  try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VtaTyperEnHi.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VtaTyperEnHi.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VtaTyperEnHi.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VtaTyperEnHi.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
		 if(argv.length > 0)
        {
            TypingLanguage = argv[0];
            
        }
        else
        {
            TypingLanguage = "En";
        }
		Loading = "Started";
      //  System.out.println(TypingLanguage+"ddd");
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VtaTyperEnHi().setVisible(true);
            }
        });
	///////////////////////////
	    String GrammerName = "";
	    String Language =TypingLanguage;
	    String lm = "";
	   if(TypingLanguage.equals("En"))
	   {
	        lm = "VtaTyperEnHi_En_NoM.trigram.lm";
	   }
	   else{
	       lm = "VtaTyperEnHi_Hi_NoM.trigram.lm";
	   }
	    
		
		
	   if (argv.length > 0)
	   {
	         int argc = argv.length;
			 int i = 0;
	        while(i<argc)
			{
			      switch(argv[i])
				  {
				     case "-g" :
					     GrammerName = argv[++i];
						 break;
				   	case "-l" :
					     Language = argv[++i];
						break;
					case "-lm" :
					     lm = argv[++i];
						break;
					 
				    default:
					   break;
					   
				  }
				  i++;
                 
		    }
	   }
	 //  Loading = "Compleat";
	    Utils.log("", "Initializing recognizer. " + "This may take some time...");
	    SpeechInterface.init(GrammerName,Language,lm);
		Loading = "Compleat";
         Utils.log("","VtaTyper Loaded Complete  Language : "+Language);

		boolean quit = false;
		Clipboard cb = Toolkit.getDefaultToolkit().getSystemClipboard();
		Robot robot = null;
		       try {
                      robot = new Robot();
                     } catch (AWTException ex) {
                      Logger.getLogger(VtaTyperEnHi.class.getName()).log(Level.SEVERE, null, ex);
                   }
		while (!quit)
		{
			 try
			{
				Thread.sleep(200);
			}
			catch (InterruptedException e)
			{
			}

			while (SpeechInterface.getRecognizerQueueSize() > 0)
			{
				String s = SpeechInterface.popRecognizedString();
				
				if(TypingLanguage.equals("Hi"))
				{
				   s =   EnToHi.EntoHi(s);
				}
			 
                    StringSelection slection = new StringSelection(s+" ");
                    cb.setContents(slection, slection);
				   
				   
				// Check if the string contains 'quit'.
			        robot.keyPress(KeyEvent.VK_CONTROL);
                     robot.keyPress(KeyEvent.VK_V);
                     robot.keyRelease(KeyEvent.VK_V);
                     robot.keyRelease(KeyEvent.VK_CONTROL);
					 
				System.out.println("[VtaSpeach] " + s + " [VtaSpeach]");
				//voce.SpeechInterface.synthesize(s);
			}
		}

		 SpeechInterface.destroy();
		System.exit(0);
	}
	
	 private javax.swing.JLabel jLabel1;
}
 