//
//  TYEventLinkCameraGroupModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/10/23.
//

#import <Foundation/Foundation.h>

@class TuyaSecurityEventRecordingBindCameraModel;

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityEventLinkCameraGroupModel : NSObject


/// Room Name
@property (nonatomic, copy) NSString *roomName;

/// Camera List
@property (nonatomic, strong) NSArray<TuyaSecurityEventRecordingBindCameraModel *> *cameraDeviceList;

@end

NS_ASSUME_NONNULL_END
