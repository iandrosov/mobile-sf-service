//
//  ViewController.swift
//  Bisknowledge
//
//  Created by Igor Androsov on 12/27/16.
//  Copyright © 2016 Igor Androsov. All rights reserved.
//

import UIKit
import ServiceCore
import ServiceKnowledge
import ServiceCases
import ServiceChat
import ServiceSOS


class ViewController: UIViewController, SCSChatDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        // Add our chat delegate
        
        SCServiceCloud.sharedInstance().chat.add(self)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func launchChat(_ sender: Any) {
        
            let config = SCSChatConfiguration(liveAgentPod: "d.la3-c2cs-phx.salesforceliveagent.com",
                                              orgId: "00D0j000000CpXq",
                                              deploymentId: "5720j000000CaSZ",
                                              buttonId: "5730j000000CaTX")
            
            // Start the session.
            
            SCServiceCloud.sharedInstance().chat.startSession(with: config)
            
    }
    
    @IBAction func launchSOS(_ sender: Any) {
        /*
        let options = SOSOptions(liveAgentPod: "d.la3-c2cs-phx.salesforceliveagent.com",
                                 orgId: "00D0j000000CpXq",
                                 deploymentId: "YOUR-DEPLOYMENT-ID")
        
        SCServiceCloud.sharedInstance().sos.startSession(with: options)
        */
        
    }
    
    @IBAction func showHelp(_ sender: Any) {
        SCServiceCloud.sharedInstance().knowledge.setInterfaceVisible(true,
                                                                      animated: true,
                                                                      completion: nil)
    }

    @IBAction func chowCase(_ sender: Any) {
        
        SCServiceCloud.sharedInstance().cases.setInterfaceVisible(true,
            animated: true,
            completion: nil)

    }
    
    
    func chat(_ chat: SCSChat!, didEndWith reason: SCSChatEndReason,
        error: Error!) {
        
        var description = ""
        
        // Here we'll handle the situation where the agent ends the session
        // and when there are no agents available...
        if (reason == .agent) {
            description = "The agent has ended the session."
        } else if (reason == .sessionError &&
            (error as NSError).code == SCSChatErrorCode.noAgentsAvailableError.rawValue) {
            description = "It looks like there are no agents available. Try again later."
        }
        
        
        if (description != "") {
            
            let alert = UIAlertController(title: "Session Ended",
                message: description,
                preferredStyle: .alert)
            
            let okAction = UIAlertAction(title: "OK",
                style: .default,
                handler: nil)
            
            alert.addAction(okAction)
            
            self.present(alert, animated: true, completion: nil)
            
        }
    }
    


}

