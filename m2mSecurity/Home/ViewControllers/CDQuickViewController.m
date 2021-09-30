//
//  CDQuickViewController.m
//  Security
//
//  Created by chendan on 2021/7/6.
//

#import "CDQuickViewController.h"
#import "UIView+ProgressView.h"
#import "CDQuickCell.h"
#import "CDHelper.h"

#import "CDHandleQuickViewController.h"
#import "ScanViewController.h"


@interface CDQuickViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *myTableView;
@property (weak, nonatomic) IBOutlet UIView *tipView;
@property (weak, nonatomic) IBOutlet UILabel *tipLab;

@property (nonatomic, strong)NSMutableArray *dataArr;
@property (weak, nonatomic) IBOutlet UIImageView *searchView;

@end

static NSString *cellID = @"cellID";
@implementation CDQuickViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = @"自动发现";
    
    [self setupTableView];
    [self startConfigWithWifi:@"1" password:@"1"];
    
    self.navigationItem.rightBarButtonItem  = [[UIBarButtonItem alloc]initWithImage:[UIImage imageNamed:@"scan"] style:UIBarButtonItemStylePlain target:self action:@selector(scan)];
    
    [self rotateView:self.searchView];
    
}

- (void)rotateView:(UIImageView *)view
{
    [view.layer removeAllAnimations];
      CABasicAnimation *rotationAnimation;
      rotationAnimation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
      rotationAnimation.removedOnCompletion = NO;
      rotationAnimation.toValue = [NSNumber numberWithFloat:M_PI*2.0];
      rotationAnimation.duration = 1.5;
      rotationAnimation.repeatCount = HUGE_VALF;
     [view.layer addAnimation:rotationAnimation forKey:@"rotationAnimation"];

}

-(void)scan{
    ScanViewController *scanVC = [[ScanViewController alloc]init];
    [self.navigationController pushViewController:scanVC animated:YES];
}

-(void)setupTableView{
    [self.myTableView registerNib:[UINib nibWithNibName:@"CDQuickCell" bundle:nil] forCellReuseIdentifier:cellID];
    self.myTableView.rowHeight = 72;
}

-(void)startConfigWithWifi:(NSString *)wifi password:(NSString *)password{
//    [self.view pv_showTextDialog:@"正在搜索门铃设备..."];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 12;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    CDQuickCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    return cell;
}



- (IBAction)handAdd:(id)sender {
    CDHandleQuickViewController *handleVC = [[CDHandleQuickViewController alloc]init];
    [self.navigationController pushViewController:handleVC animated:YES];
}


@end
