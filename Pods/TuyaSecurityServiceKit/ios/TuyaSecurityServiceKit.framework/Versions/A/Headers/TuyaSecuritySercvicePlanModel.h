//
//  TYSecuritySercvicePlanModel.h
//  TYSecurityUserCenterBizKit
//
//  Created by Tuya.Inc on 2021/4/25.
//

#import <Foundation/Foundation.h>

#import <YYModel/YYModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityServiceComboLevel) {
    TYSecurityServiceComboLevelDefault = 0,//无服务
    TYSecurityServiceComboLevelAdvance = 1,// 基础
    TYSecurityServiceComboLevelProfessional = 2, //高级
    TYSecurityServiceComboLevelStandard = 3, //free
    TYSecurityServiceComboLevelCustom = 5 //自定义套餐
};

typedef NS_ENUM(NSInteger, TYSecurityServiceComboType) {
    TYSecurityServiceComboTypeNormal = 0,//普通类型
    TYSecurityServiceComboTypeSubscribe = 1// 订阅类型
};


typedef NS_ENUM(NSInteger, TYSecurityServiceComboConfigStatus) {
    TYSecurityServiceComboConfigUndefined = 0,//未配置
    TYSecurityServiceComboConfigDefined = 1//已配置
};


@interface TuyaSecuritySercvicePlanModel : NSObject

/// 家庭Id
@property(nonatomic, copy) NSString *homeId;

/// 已购买套餐描述
@property(nonatomic, copy) NSString *commodityDesc;

@property (nonatomic, copy) NSString *commodityCode;

/// 套餐类型
@property(nonatomic, assign) TYSecurityServiceComboLevel comboLevel;

/// 订阅类型类型， //0=普通类型，1=连续订阅类型
@property(nonatomic, assign) TYSecurityServiceComboType comboType;

/// 配置类型
@property(nonatomic, assign) TYSecurityServiceComboConfigStatus configFlag;

///是否过期//create, running, expire
@property(nonatomic, copy) NSString *state;

/// 套餐商品码
@property (nonatomic, copy) NSString *code;

@property(nonatomic, assign) NSTimeInterval serviceEffectiveTime;

@property(nonatomic, assign) NSTimeInterval serviceExpiredTime;

//有效的服务类型
- (BOOL)isEffectiveService;


@end

NS_ASSUME_NONNULL_END
