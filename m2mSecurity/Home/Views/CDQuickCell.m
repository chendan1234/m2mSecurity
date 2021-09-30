//
//  CDQuickCell.m
//  Security
//
//  Created by chendan on 2021/7/6.
//

#import "CDQuickCell.h"
#import "AddDeviceViewController.h"

@interface CDQuickCell ()
@property (weak, nonatomic) IBOutlet UILabel *nameLab;
@property (weak, nonatomic) IBOutlet UILabel *desLab;

@end

@implementation CDQuickCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (IBAction)add:(id)sender {
    AddDeviceViewController *addVC = [[AddDeviceViewController alloc]init];
    [[CDHelper viewControllerWithView:self].navigationController pushViewController:addVC animated:YES];
}

@end
