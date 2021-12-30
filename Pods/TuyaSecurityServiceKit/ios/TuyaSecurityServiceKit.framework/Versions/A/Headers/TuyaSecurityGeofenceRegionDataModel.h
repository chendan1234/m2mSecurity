//
//  TYGeoHomesModel.h
//  TYSecurityComponents
//
//  Created by Tuya.Inc on 2019/9/2.
//

#import <Foundation/Foundation.h>

/*
 enable = 1;
 fenceData = "{\"lon\":\"1233\",\"radius\":\"100\",\"title\":\"test\",\"lat\":\"5646\"}";
 fenceId = "d91f5b11-db78-11e9-ad55-0242ee690017";
 gmtCreate = 1568964769678;
 gmtModified = 1569209806818;
 homeId = 8784083;
 lat = 5646;
 lon = 1233;
 radius = 100;
 title = test;
 */
NS_ASSUME_NONNULL_BEGIN


@interface TuyaSecurityGeofenceRegionItemModel : NSObject


/// latitude
@property(nonatomic, assign) double lat;

/// longitude
@property(nonatomic, assign) double lon;

/// Whether the family location has been set
@property(nonatomic, assign) BOOL isSettedLocation;

/// radius
@property(nonatomic, assign) double radius;

///  Location's name
@property(nonatomic, copy) NSString *title;

@end

@interface TuyaSecurityGeofenceRegionDataModel : NSObject


///  Geofence Unique identification ID
@property(nonatomic, copy) NSString *fenceId;

///  Home ID
@property(nonatomic, assign) long long homeId;

///  Create Time
@property(nonatomic, assign) NSTimeInterval gmtCreate;

///  Modify Time
@property(nonatomic, assign) NSTimeInterval gmtModified;

///  Whether to join in Geofenc
@property(nonatomic, assign) NSInteger enable;

///  Geofence Region Data
@property(nonatomic, strong) TuyaSecurityGeofenceRegionItemModel *data;
@end

NS_ASSUME_NONNULL_END
