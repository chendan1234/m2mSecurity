//
//  TuyaSecurityMessageKitDefinition.h
//  Pods
//
//  Created by Tuya.Inc on 2020/5/12.
//

#ifndef TuyaSecurityMessageKitDefinition_h
#define TuyaSecurityMessageKitDefinition_h

typedef NS_ENUM(NSInteger,TYSecurityArmedMsgType) {
    TYSecurityArmedMsgTypeAll = 0,// All Messages
    TYSecurityArmedMsgActivityType = 1,// activity Message
    TYSecurityArmedMsgNotificationType = 2,// Notification Message
    
};

typedef NS_ENUM(NSInteger,TYSecurityMessageDealType) {
    TYSecurityMessageDealTypeUnDeal = 0,// Undisposed Message
    TYSecurityMessageDealTypeUnDealToo = 1,// Undisposed Message
    TYSecurityMessageDealTypeUnlock = 2,// Cancel The Alarm Message
    TYSecurityMessageDealTypeConnected = 3,// Emergency Contact
    TYSecurityMessageDealTypeCallSercice = 4//  Call Security Services
    
};

typedef NS_ENUM(NSInteger,TYSecurityMessageFavoriteState) {
    TYSecurityMessageRemoveFavorite = 0,// Cancel Collection
    TYSecurityMessageSetFavorite = 1// Collection
};

#endif /* TuyaSecurityMessageKitDefinition_h */
