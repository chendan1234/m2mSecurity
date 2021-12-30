//
//  TYSPurchasedSercviceComboModel.h
//  TYSecurityUserCenterBizKit
//
//  Created by Tuya.Inc on 2021/4/26.
//

#import <Foundation/Foundation.h>

#import "TYSPurchasedSercviceComboOrder.h"
#import "TuyaSecurityPlatformSercviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityPurchasedSercviceComboModel : NSObject

//free:免费单, ultimate:高级套餐, interactive:基础套餐, custom:自定义套餐, business:商业套餐
@property (nonatomic, copy) NSString *code;

//1:基础套餐, 3:免费单, 2:高级套餐, 4:商业套餐
@property (nonatomic, assign) NSUInteger commodityLevel;

@property (nonatomic, copy) NSString *channelId;

@property (nonatomic, copy) NSString *dealerId;

@property (nonatomic, strong) TuyaSecurityPlatformSercviceModel *ecommodity;

@property (nonatomic, strong) TYSPurchasedSercviceComboOrder *serviceInfo;


@end

NS_ASSUME_NONNULL_END
