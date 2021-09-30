//
//  HomeViewController.m
//  m2mSecurity
//
//  Created by chendan on 2021/8/16.
//

#import "HomeViewController.h"
#import "CDDevicelistViewController.h"
#import <LSTPopView.h>
#import "MyHomeListView.h"
#import "HomeManageViewController.h"
#import "CDQuickViewController.h"
#import "DeviceInfoViewController.h"

@interface HomeViewController ()<UIScrollViewDelegate>
@property (weak, nonatomic) IBOutlet UIView *navBgView;
@property(nonatomic,weak)UIView *lineView;
@property(nonatomic,weak)UIScrollView *scrollV;
@property(nonatomic,weak)UIButton *selectedBtn;
@property (weak, nonatomic) IBOutlet UIButton *collectionBtn;
@property (weak, nonatomic) IBOutlet UIButton *tableBtn;
@property (weak, nonatomic) IBOutlet UIImageView *touXiangImgV;
@property (weak, nonatomic) IBOutlet UIView *myHomeView;
@property (weak, nonatomic) IBOutlet UILabel *homeLab;
@property (weak, nonatomic) IBOutlet UILabel *statusLab;//状态
@property (weak, nonatomic) IBOutlet UIImageView *downImgV;//向下箭头

@property (nonatomic, strong)TuyaSmartHomeModel *model;
@property(strong, nonatomic) TuyaSmartHomeManager *homeManager;
@property (nonatomic, assign)NSInteger homeId;

@property (nonatomic,assign)bool isTableView;


@end

@implementation HomeViewController

- (TuyaSmartHomeManager *)homeManager {
    if (!_homeManager) {
        _homeManager = [[TuyaSmartHomeManager alloc] init];
    }
    return _homeManager;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.homeId = [CDHelper getHomeId];
    
    [self setupUI];
    
    [self setupHome];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"KHaveNoti" object:@"5"];
}

//获取家庭
-(void)setupHome{
    __weak typeof(self) weakSelf = self;
    
//    [self.view pv_showTextDialog:@"正在加载..."];
    [self.homeManager getHomeListWithSuccess:^(NSArray<TuyaSmartHomeModel *> *homes) {
        [weakSelf.view pv_hideMBHub];
        // homes 家庭列表
        if (self.homeId) {//有家庭的情况下
            for (TuyaSmartHomeModel *model in homes) {
                if (self.homeId == model.homeId) {
                    weakSelf.model = model;
                    weakSelf.homeLab.text = model.name;
                }
            }
        }else{//没有获取到homeId的时候
            weakSelf.model = [homes firstObject];
            if (weakSelf.model) {
                weakSelf.homeLab.text = weakSelf.model.name;
                [CDHelper setupHomeId:weakSelf.model.homeId];
            }
        }
        
        if (weakSelf.model) {
            [self setupDevice];
        }
        
    } failure:^(NSError *error) {
        
    }];
}

//获取设备
-(void)setupDevice{
    for (CDDevicelistViewController *vc in self.childViewControllers) {
        [vc setupHomeDevice];
    }
}

-(void)setupUI{
    self.title = @"首页";
    self.collectionBtn.enabled = NO;
    [self.touXiangImgV sd_setImageWithURL:[NSURL URLWithString:[CDAppUser getUser].avatarUrl] placeholderImage:[UIImage imageNamed:@"user"]];
    
    UIBarButtonItem *rightItem = [[UIBarButtonItem alloc]initWithImage:[UIImage imageNamed:@"add"] style:UIBarButtonItemStylePlain target:self action:@selector(addDevice)];
    self.navigationItem.rightBarButtonItem = rightItem;
    
    [self.myHomeView addGestureRecognizer:[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(myHomeViewClick)]];
    
    [self setnavView];
    [self setChildrenVC];
    [self setContentView];
}

//添加设备
-(void)addDevice{
    CDQuickViewController *addVC = [[CDQuickViewController alloc]init];
    [self.navigationController pushViewController:addVC animated:YES];
}

//选择家庭
-(void)myHomeViewClick{
    MyHomeListView *homeListV = [MyHomeListView reload];
    homeListV.frame = CGRectMake(0, 0, 250, 280);
    
    homeListV.layer.cornerRadius = 10;
    homeListV.layer.masksToBounds = YES;
    
    LSTPopView *popView = [LSTPopView initWithCustomView:homeListV popStyle:LSTPopStyleScale dismissStyle:LSTDismissStyleScale];
    popView.popDuration = 0.5;
    popView.dismissDuration = 0.5;
    LSTPopViewWK(popView)
    [popView pop];
    
    [popView setBgClickBlock:^{
        [wk_popView dismiss];
    }];
    
    [homeListV setMyBlock:^(NSInteger type, TuyaSmartHomeModel * _Nonnull model) {
        [wk_popView dismiss];
        
        if (type) {
            HomeManageViewController *homeManageVC = [[HomeManageViewController alloc]init];
            [homeManageVC setDeleteSelectBlock:^{//删除了本来的家庭
                self.model = nil;
                self.homeLab.text = @"添加家庭";
                [CDHelper setupHomeId:0];
                [self setupDevice];
            }];
            [self.navigationController pushViewController:homeManageVC animated:YES];
        }else{
            self.homeLab.text = model.name;
            self.model = model;
            [CDHelper setupHomeId:model.homeId];
            [self setupDevice];
        }
    }];
}


- (IBAction)tableBtnClick:(UIButton *)sender {
    self.tableBtn.enabled = NO;
    self.collectionBtn.enabled = YES;
    
    for (CDDevicelistViewController *listVC in self.childViewControllers) {
        [listVC exchangeLayout:YES];
    }
    
    self.isTableView = YES;
}

- (IBAction)collectionBtnClick:(UIButton *)sender {
    self.collectionBtn.enabled = NO;
    self.tableBtn.enabled = YES;
    
    for (CDDevicelistViewController *listVC in self.childViewControllers) {
        [listVC exchangeLayout:NO];
    }
    
    self.isTableView = NO;
}

//关锁
- (IBAction)close:(id)sender {
    
}

//开锁
- (IBAction)open:(id)sender {
    
}

//家庭
- (IBAction)home:(id)sender {
    
}

//sos
- (IBAction)sos:(id)sender {
    
}

//设置
- (IBAction)setting:(id)sender {
    TuyaSmartDeviceModel *deviceModel = [CDHelper getWangGuanModel];
    if (deviceModel) {
        DeviceInfoViewController *infoVC = [[DeviceInfoViewController alloc]init];
        infoVC.deviceModel = deviceModel;
        infoVC.form = DeviceInfoFormWangGuan;
        [self.navigationController pushViewController:infoVC animated:YES];
    }else{
        [CDHelper setupOneBtnAlterWithVC:self title:@"无法操作" message:@"请先连接网关设备, 再进行操作" sure:^{}];
    }
    
}


-(void)setnavView{
    
    
    UIView *bgV = [[UIView alloc]initWithFrame:CGRectMake(0, 0, DEVICE_WIDRH - 112, 50)];
    [self.navBgView addSubview:bgV];
    
    
    UIView *lineView = [[UIView alloc]init];
    lineView.height = 4;
    lineView.y = 46;
    self.lineView = lineView;
    lineView.backgroundColor = KColorA(72, 144, 223, 1);
    [bgV addSubview:lineView];
    
    
    NSArray *titleArr = @[@"全部设备",@"共享设备"];
    NSInteger count = titleArr.count;
    CGFloat btnW = 100;
    CGFloat btnH = bgV.height;
    CGFloat btnY = 0;
    for (int i = 0 ; i < count; i++) {
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
        btn.frame = CGRectMake(i * btnW, btnY, btnW, btnH);
        btn.tag = 100 + i;
        [btn setTitle:titleArr[i] forState:UIControlStateNormal];
        [btn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
        [btn setTitleColor:KColorA(72, 144, 223, 1) forState:UIControlStateDisabled];
        btn.titleLabel.font = [UIFont systemFontOfSize:14];
        [btn addTarget:self action:@selector(navBtnClick:) forControlEvents:UIControlEventTouchUpInside];
        btn.titleLabel.font = [UIFont boldSystemFontOfSize:18];
        [bgV addSubview:btn];
        
        
        if (i == 0) {
            btn.enabled = NO;
            self.selectedBtn = btn;
            [btn.titleLabel sizeToFit];
            self.lineView.width = btn.titleLabel.width;
            self.lineView.centerX= btn.centerX;
        }
    }
}




-(void)navBtnClick:(UIButton *)sender{
    
    self.selectedBtn.enabled = YES;
    sender.enabled = NO;
    self.selectedBtn = sender;
    
    [UIView animateWithDuration:0.25 animations:^{
        self.lineView.width = sender.titleLabel.width;
        self.lineView.centerX= sender.centerX;
    }];
    
    CGPoint point = self.scrollV.contentOffset;
    point.x = (sender.tag - 100) * self.scrollV.width;
    [self.scrollV setContentOffset:point animated:YES];
}


-(void)setContentView{
    CGFloat Y = self.navigationController.navigationBar.frame.size.height + [[UIApplication sharedApplication] statusBarFrame].size.height + 230;
    CGFloat H = DEVICE_HEIGHT - Y - self.tabBarController.tabBar.bounds.size.height;
    UIScrollView *scrollV = [[UIScrollView alloc]initWithFrame:CGRectMake(0, Y, DEVICE_WIDRH, H)];
    scrollV.contentSize = CGSizeMake(self.childViewControllers.count * scrollV.width, 0);
    scrollV.pagingEnabled = YES;
    scrollV.bounces = NO;
    scrollV.delegate = self;
    scrollV.showsHorizontalScrollIndicator = NO;
    self.scrollV = scrollV;
    
    [self.view addSubview:scrollV];
    [self scrollViewDidEndScrollingAnimation:self.scrollV];
    [self.scrollV.panGestureRecognizer requireGestureRecognizerToFail:self.navigationController.interactivePopGestureRecognizer];
}

-(void)setChildrenVC{
    
    CDDevicelistViewController *allVC = [[CDDevicelistViewController alloc]init];
    allVC.type = 1;
    
    CDDevicelistViewController *shareVC = [[CDDevicelistViewController alloc]init];
    shareVC.type = 2;
    
    [self addChildViewController:allVC];
    [self addChildViewController:shareVC];
}

-(void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView
{
    NSInteger index = scrollView.contentOffset.x / scrollView.width;
    CDDevicelistViewController *vc = self.childViewControllers[index];
    
    vc.view.x = index * scrollView.width;
    vc.view.width = scrollView.width;
    vc.view.height = scrollView.height;
    [self.scrollV addSubview:vc.view];
    for (CDDevicelistViewController *vc in self.childViewControllers) {
        [vc exchangeLayout:self.isTableView];
    }
}

-(void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
    [self scrollViewDidEndScrollingAnimation:scrollView];
    
    NSInteger index = scrollView.contentOffset.x / scrollView.width;
    [self navBtnClick:(UIButton *)[self.navBgView viewWithTag:index + 100]];
}



@end
