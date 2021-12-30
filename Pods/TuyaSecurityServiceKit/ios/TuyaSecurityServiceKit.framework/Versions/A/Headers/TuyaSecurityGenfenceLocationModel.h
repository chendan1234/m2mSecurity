//
//  TYGenfenceLocationModel.h
//  BlocksKit
//
//  Created by 浩天 on 2019/5/17.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class TuyaSecurityGeofenceRegionDataModel;

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSecurityGenfenceLocationModel : NSObject

@property (nonatomic, assign) double geoRadius;
@property (nonatomic, assign) double geoLati;
@property (nonatomic, assign) double geoLonti;
@property (nonatomic, copy, nullable) NSString *geoTitle;
@property (nonatomic, strong, nullable) CLPlacemark *placemark;
@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) BOOL isCommit;

- (CLLocation *)geoLocation;

+ (TuyaSecurityGenfenceLocationModel *)transformGeoFencingWith:(TuyaSecurityGeofenceRegionDataModel *)dataModel;

@end

NS_ASSUME_NONNULL_END
