//
//  TuyaSecurityEventRecording.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/18.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

@class TuyaSecurityEventRecordingSensorModel;
@class TuyaSecurityEventRecordingLinkRuleModel;
@class TuyaSecurityEventRecordingLinkTaskModel;


typedef void (^EventRecordingSensorList)(NSArray<TuyaSecurityEventRecordingSensorModel *> * _Nullable sensorList);

typedef void (^EventRecordingCameraLink)(TuyaSecurityEventRecordingLinkRuleModel * _Nullable linkRuleModel);

typedef void (^EventRecordingStorageBindCameraList)(NSArray<NSString *> * _Nullable cameraList);



NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityEventRecording : NSObject

/// singleInstance
+ (instancetype)sharedInstance;


/// Gets a list of sensing devices
///
/// @param homeId  Home ID
/// @param success  Success Callback
/// @param failure  Fauilre Callback
- (void)getSensorList:(long long)homeId
              success:(EventRecordingSensorList)success
              failure:(TYFailureError)failure;


/// Gets a list of cameras for the specified sensor bindings
///
/// @param homeId  Home ID
/// @param deviceId sensor Id
/// @param success  Success Callback
/// @param failure  Fauilre Callback
- (void)getLinkedCameras:(long long)homeId
                deviceId:(NSString *)deviceId
                 success:(EventRecordingCameraLink)success
                 failure:(TYFailureError)failure;


/// Bind Cameras
///
/// @param homeId Home ID
/// @param taskModel task Model
/// @param success  Success Callback
/// @param failure  Fauilre Callback
- (void)linkCamera:(long long)homeId
         taskModel:(TuyaSecurityEventRecordingLinkTaskModel *)taskModel
           success:(TYSuccessBOOL)success
           failure:(TYFailureError)failure;


/// Gets the list of cameras that have been bound to the cloud storage
///
/// @param homeId  Home ID
/// @param nCameraIdList camera list
/// @param success Success Callback
/// @param failure Fauilre Callback
- (void)getStorageBindCameraList:(long long)homeId
                    cameraIdList:(NSArray<NSString *> *)nCameraIdList
                         success:(EventRecordingStorageBindCameraList)success
                         failure:(TYFailureError)failure;



@end

NS_ASSUME_NONNULL_END
