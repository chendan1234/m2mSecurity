//
//  TuyaSecuritySceneManager.h
//  TuyaSecuritySceneKit
//
//  Created by Tuya.Inc on 2020/5/13.
//

#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>

@class TuyaSecuritySceneAlarmTypeModel;


NS_ASSUME_NONNULL_BEGIN

typedef void(^AlarmTypeListBlock)(NSArray<TuyaSecuritySceneAlarmTypeModel *> *dataArray);


@interface TuyaSecuritySceneManager : TuyaSmartRequest

/// singleInstance
+ (instancetype)sharedInstance;

/// get Alarm list by Scene
/// @param homeId homeId
/// @param success success
/// @param failure failure
- (void)getSceneAlarmTypeListWithHomeId:(long long)homeId
                                 success:(AlarmTypeListBlock)success
                                 failure:(TYFailureError)failure;




@end

NS_ASSUME_NONNULL_END
