//
//  TuyaSecurityCameraSaveModel.h
//  TuyaSecuritySDK
//
//  Copyright (c) 2014-2021 Tuya (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import "TuyaSecurityCameraBindType.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityCameraSaveModel : NSObject

/// ID of the camera
@property (nonatomic, copy) NSString *deviceId;

/// bind type
@property (nonatomic, assign) TuyaSecurityCameraBindType type;


@end

NS_ASSUME_NONNULL_END

