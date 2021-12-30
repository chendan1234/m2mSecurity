//
//  TYSPurchasedSercviceComboOrder.h
//  TYSecurityUserCenterBizKit
//
//  Created by Tuya.Inc on 2021/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYSPurchasedSercviceComboOrder : NSObject

@property (nonatomic, assign) NSInteger serviceOrderStatus;

@property (nonatomic, copy) NSString *serviceOrderStartDate;
@property (nonatomic, copy) NSString *serviceOrderEndDate;

@property (nonatomic, copy) NSString *subscriptionId;

@property (nonatomic, assign) NSInteger subscriptionStatus;

@property (nonatomic, copy) NSString *nextDeductTime;

@end

NS_ASSUME_NONNULL_END
