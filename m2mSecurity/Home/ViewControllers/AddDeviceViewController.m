//
//  AddDeviceViewController.m
//  m2mSecurity
//
//  Created by chendan on 2021/8/20.
//

#import "AddDeviceViewController.h"
#import <LSTPopView.h>
#import "SelectHomeView.h"

@interface AddDeviceViewController ()
@property (weak, nonatomic) IBOutlet UIView *homeBgView;
@property (weak, nonatomic) IBOutlet UIImageView *iconV;
@property (weak, nonatomic) IBOutlet UILabel *deviceNameLab;

@end

@implementation AddDeviceViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = @"添加设备";
    
    [self.homeBgView addGestureRecognizer:[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(homeBgViewClick)]];
}

-(void)homeBgViewClick{
    SelectHomeView *homeV = [SelectHomeView reload];
    homeV.frame = CGRectMake(0, 0, 270, 320);
    homeV.layer.cornerRadius = 5.0;
    homeV.layer.masksToBounds = YES;
    
    LSTPopView *popView = [LSTPopView initWithCustomView:homeV popStyle:LSTPopStyleSpringFromTop dismissStyle:LSTDismissStyleScale];
    popView.popDuration = 0.5;
    popView.dismissDuration = 0.5;
    LSTPopViewWK(popView)
    [popView pop];
    
    [homeV setMyBlock:^{
        [wk_popView dismiss];
    }];
    
}
- (IBAction)edit:(id)sender {
    [CDHelper setupTFAlertWithVC:self title:@"修改设备名称" placeHolder:@"请输入设备名称" sure:^(NSString * _Nonnull tf) {
        NSLog(@"设备名称修改成功!");
    }];
}

- (IBAction)over:(id)sender {
    [self.navigationController popToRootViewControllerAnimated:YES];
}


@end
