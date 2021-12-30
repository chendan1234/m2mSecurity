//
//  TYUserServiceModel.h
//  BlocksKit
//
//  Created by Tuya.Inc on 2020/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityUserServiceModel : NSObject

/// is Bind Service Code.
@property (nonatomic, assign) NSInteger isBind;

/// Service code
@property (nonatomic, copy) NSString *code;

/// channel ID
@property (nonatomic, copy) NSString *channelId;

/// Delaer ID
@property (nonatomic, copy) NSString *dealerId;

@end

NS_ASSUME_NONNULL_END
