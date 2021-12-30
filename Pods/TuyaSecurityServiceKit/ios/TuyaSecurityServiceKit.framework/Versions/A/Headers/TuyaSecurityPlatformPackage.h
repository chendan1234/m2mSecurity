//
//  TuyaSecurityPlatformPackage.h
//  AFNetworking
//
//  Created by Tuya.Inc on 2021/7/29.
//

#import <Foundation/Foundation.h>
#import <TUyaSmartUtil/TuyaSmartUtil.h>

@class TuyaSecuritySercvicePlanModel, TuyaSecurityPlatformSercviceListModel, TuyaSecurityPurchasedSercviceComboModel;

typedef void(^FetchSecurityServicePlanSuccess)(TuyaSecuritySercvicePlanModel *servicePlan);

typedef void(^FetchSecurityPlatformServiceSuccess)(TuyaSecurityPlatformSercviceListModel *sercviceList);

typedef void(^FetchSecurityPurchasedServiceComboSuccess)(TuyaSecurityPurchasedSercviceComboModel *sercviceCombo);


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityPlatformPackage : NSObject

/// singleInstance
+ (instancetype)sharedInstance;


/// fetch package from home
/// @param homeId homeId
/// @param success success
/// @param failure failure
- (void)fetchServicePlanWith:(long long)homeId
                     success:(FetchSecurityServicePlanSuccess)success
                     failure:(TYFailureError)failure;


/// fetch services list
/// @param homeId homeId
/// @param success success
/// @param failure failure
- (void)fetchPlatformServicesWith:(long long)homeId
                          success:(FetchSecurityPlatformServiceSuccess)success
                          failure:(TYFailureError)failure;


/// fetch user current purchased service
/// @param homeId homeId
/// @param success success
/// @param failure failure
- (void)fetchPurchasedServiceComboWith:(long long)homeId
                               success:(FetchSecurityPurchasedServiceComboSuccess)success
                               failure:(TYFailureError)failure;


/// fetch user current purchased service
/// @param homeId homeId
/// @param categoryCode category code, eg:security, maintenance_service, managed_service
/// @param ecommodityCode ecommodity code
/// @param success success
/// @param failure failure
- (void)fetchPurchasedServiceComboStatusWithCategoryCode:(long long)homeId
                                            categoryCode:(NSString *)categoryCode
                                           commodityCode:(NSString *)ecommodityCode
                                                 success:(FetchSecurityPurchasedServiceComboSuccess)success
                                                 failure:(TYFailureError)failure;

/// fetch user current purchased service
/// @param homeId homeId
/// @param categoryCode categoryCode category code, eg:security, maintenance_service, managed_service
/// @param success success
/// @param failure failure
- (void)fetchServiceComboPurchasedFlagWith:(long long)homeId
                              categoryCode:(NSString *)categoryCode
                                   success:(TYSuccessBOOL)success
                                   failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
