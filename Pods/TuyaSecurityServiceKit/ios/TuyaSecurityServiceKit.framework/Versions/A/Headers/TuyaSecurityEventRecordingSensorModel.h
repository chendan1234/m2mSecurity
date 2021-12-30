//
//  TYEventSensorModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/10/23.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger,TYEventRecordingCameraBindingType) {
    //
    TYEventRecordingCameraBindingTypeImage = 1,
    TYEventRecordingCameraBindingTypeVideo = 2
};

typedef NS_ENUM(NSInteger, TYEventLinkCameraSupportType){
    TYEventLinkCameraSupportTypeOnlyImage = 1,
    TYEventLinkCameraSupportTypeBoth = 2
};

static NSString * const _Nullable kLinkTypeImage = @"image";
static NSString * const _Nullable kLinkTypeVedio = @"video";


@interface TuyaSecurityEventRecordingLinkTaskCameraModel : NSObject


/// Camera ID
@property (nonatomic, copy) NSString *cameraId;

/// BindType
@property (nonatomic, assign) TYEventRecordingCameraBindingType type;

///
@property (nonatomic, assign) BOOL isSelected;

@end

@interface TuyaSecurityEventRecordingLinkTaskModel : NSObject

/// Rule Id
@property (nonatomic, copy) NSString *ruleId;

/// sensor Id
@property (nonatomic, copy) NSString *sensorId;

/// product Id
@property (nonatomic, copy) NSString *productId;

@property (nonatomic, strong) NSArray<TuyaSecurityEventRecordingLinkTaskCameraModel *> *cameraModelList;

@end




@interface TuyaSecurityEventRecordingBindCameraModel : NSObject


// rule Id
@property (nonatomic, copy) NSString *ruleId;

// order
@property (nonatomic) NSInteger order;

/// Camera Device ID
@property (nonatomic, copy) NSString *entityId;

///  Camera binding type
@property (nonatomic, assign) TYEventRecordingCameraBindingType type;

///  Device information
@property (nonatomic, strong) TuyaSmartDeviceModel *deviceModel;

/// Supported binding types
@property (nonatomic, assign) TYEventLinkCameraSupportType linkCameraSupportType;

@end


@interface TuyaSecurityEventRecordingSensorModel : NSObject

///  Device ID
@property (nonatomic, copy) NSString *deviceId;

///  List of cameras
@property (nonatomic, strong) NSArray<TuyaSecurityEventRecordingBindCameraModel *> *actionInfos;

/// Whether it has been attached to the camera
@property (nonatomic, assign) BOOL linked;

///  Device information
@property (nonatomic, strong) TuyaSmartDeviceModel *deviceModel;

@end

NS_ASSUME_NONNULL_END
