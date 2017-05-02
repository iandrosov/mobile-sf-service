//
//  AppDelegate.swift
//  Bisknowledge
//
//  Created by Igor Androsov on 12/27/16.
//  Copyright © 2016 Igor Androsov. All rights reserved.
//

import UIKit
import ServiceCore
import ServiceKnowledge
import ServiceCases

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        //////////////////////////// knwldgedev-bisk.cs59.force.com
        // Create configuration object with init params
        // "https://developer-week-developer-edition.na16.force.com" 	https://awesomedev-awesomedev.cs53.force.com
        //let config = SCSServiceConfiguration(
        //    community: URL(string: "https://developer-week-developer-edition.na55.force.com")!,
        //    dataCategoryGroup: "Institutions",
        //    rootDataCategory: "All")

        let config = SCSServiceConfiguration(
            community: URL(string: "https://awesomedev-awesomedev.cs53.force.com")!,
            dataCategoryGroup: "Institutions",
            rootDataCategory: "All")
        
        // Perform any additional configuration here
        
        // Pass configuration to shared instance
        SCServiceCloud.sharedInstance().serviceConfiguration = config
        
        // Create appearance configuration object with some appearance changes
        //let appearance = SCAppearanceConfiguration()
        //appearance.setColor(UIColor.green, forName: SCSAppearancePrimaryBrandColor)
        //appearance.setColor(UIColor.red, forName: SCSAppearanceBrandContrastColor)
        //appearance.setColor(UIColor.black, forName: SCSAppearanceContrastPrimaryColor)
        
        // Pass appearance configuration to shared instance
        //SCServiceCloud.sharedInstance().appearanceConfiguration = appearance
        
        // Enable Knowledge
        SCServiceCloud.sharedInstance().knowledge.isEnabled = true
        
        SCServiceCloud.sharedInstance().cases.caseCreateActionName = "Case"
        SCServiceCloud.sharedInstance().cases.isEnabled = true
        
        ///////////////////////
        
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

