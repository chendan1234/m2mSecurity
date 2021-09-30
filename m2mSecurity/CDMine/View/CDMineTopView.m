//
//  CDMineTopView.m
//  security
//
//  Created by chendan on 2021/6/21.
//

#import "CDMineTopView.h"

@interface CDMineTopView ()
@property (weak, nonatomic) IBOutlet UIImageView *iconImgV;
@property (weak, nonatomic) IBOutlet UILabel *nameLab;
@property (weak, nonatomic) IBOutlet UILabel *accountLab;
@property (weak, nonatomic) IBOutlet UILabel *expireLab;

@end

@implementation CDMineTopView

+(instancetype)reload
{
    return [[[NSBundle mainBundle]loadNibNamed:@"CDMineTopView" owner:nil options:nil]lastObject];
}

-(void)setUpInfo{
    CDAppUser *user = [CDAppUser getUser];
    
    [self.iconImgV sd_setImageWithURL:[NSURL URLWithString:user.avatarUrl] placeholderImage:[UIImage imageNamed:@"user"]];
    self.nameLab.text = user.username;
    self.accountLab.text = [[NSUserDefaults standardUserDefaults] objectForKey:KLoginAccount];
//    self.expireLab.text = [NSString stringWithFormat:@"到期时间: %ld",user.expireTime];
}

@end
