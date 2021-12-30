//
//  AppDelegate.m
//  m2mSecurity
//
//  Created by chendan on 2021/8/11.
//

#import "AppDelegate.h"
#import "TabBarViewController.h"
#import "CDLoginViewController.h"
#import "NewFeatureViewController.h"
#import "CameraDoorbellManager.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [[TuyaSmartSDK sharedInstance] startWithAppKey:@"rjvtrskdsgp4mhdep8mw" secretKey:@"3n3fpe3uuhpxxu3kqfrwjhpqt4ehfxjx"];
    // Doorbell Observer. If you have a doorbell device
    [[CameraDoorbellManager sharedInstance] addDoorbellObserver];
    
    #ifdef DEBUG
//    [[TuyaSmartSDK sharedInstance] setDebugMode:YES];
    #else
    #endif
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    
    if ([[NSUserDefaults standardUserDefaults] objectForKey:KNewFeature]) {
        if ([CDAppUser getUser].isLogin) {
            self.window.rootViewController = [[TabBarViewController alloc]init];
        }else{
            self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[[CDLoginViewController alloc]init]];
        }
    }else{
        self.window.rootViewController = [[NewFeatureViewController alloc]init];
    }
    
    
    
    [self.window makeKeyAndVisible];
    
    
    
    return YES;
}






@end
