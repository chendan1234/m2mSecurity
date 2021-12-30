//
//  TuyaSecurityHomeArmedSwitchModel.h
//  TuyaSecuritySDK
//
//  Copyright (c) 2014-2021 Tuya (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import "TYSecurityArmAbilityEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityHomeArmedSwitchModel : NSObject

/// gateway devices
@property (nonatomic, strong) NSArray<NSString *>*gatewayList;

/// current mode
@property (nonatomic, assign) TYSecurityArmMode mode;


@end

NS_ASSUME_NONNULL_END

