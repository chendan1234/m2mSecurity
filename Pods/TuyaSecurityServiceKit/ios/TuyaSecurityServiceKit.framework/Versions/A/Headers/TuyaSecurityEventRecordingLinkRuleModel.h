//
//  TYEventLinkRuleModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2019/10/23.
//

#import <Foundation/Foundation.h>

@class TuyaSecurityEventRecordingBindCameraModel;

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityEventRecordingLinkRuleModel : NSObject


///  Rule ID
@property(nonatomic, copy) NSString *ruleId;

///  Device ID
@property(nonatomic, copy) NSString *deviceId;

///  cameras for the specified sensor bindings
@property(nonatomic, strong) NSArray<TuyaSecurityEventRecordingBindCameraModel *> *actionInfos;

@end

NS_ASSUME_NONNULL_END
