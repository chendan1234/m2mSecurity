//
//  TuyaSecurityArmReminder.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/12.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TuyaSecurityArmReminderModel.h"

typedef void(^ArmReminderList)(NSArray<TuyaSecurityArmReminderModel *> * _Nullable armReminderList);


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityArmReminder : NSObject

/// singleInstance
+ (instancetype)sharedInstance;


/// Get ArmReminder list
///
/// @param homeId Home ID
/// @param success Success Callback
/// @param failure Failure Callback
- (void)getArmReminderStatus:(long long)homeId
                     success:(ArmReminderList)success
                     failure:(TYFailureError)failure;


/// Modify ArmReminder
///
/// @param homeId Home ID
/// @param type Arm Type
/// @param enable  yes /no
/// @param success Success Callback
/// @param failure Failure Callback
- (void)updateArmReminderStatus:(long long)homeId
                           type:(TYArmReminderType)type
                         enable:(BOOL)enable
                        success:(TYSuccessBOOL)success
                        failure:(TYFailureError)failure;

/// Ignore ArmReminder
/// @param homeId  Home ID
/// @param success Success Callback
/// @param failure Failure Callback
- (void)ignoreArmReminder:(long long)homeId
                  success:(TYSuccessBOOL)success
                  failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
