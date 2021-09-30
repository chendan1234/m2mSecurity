//
//  MessageViewController.m
//  m2mSecurity
//
//  Created by chendan on 2021/8/16.
//

#import "MessageViewController.h"
#import "UITabBar+CustomBadge.h"
#import "MessageCell.h"

@interface MessageViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *myTableView;

@end

static NSString *cellID = @"cellID";
@implementation MessageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.navigationItem.title = @"消息中心";
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithTitle:@"全部已读" style:UIBarButtonItemStylePlain target:self action:@selector(allRead)];
    [self setupTableView];
}

-(void)allRead{
    
}

-(void)setupTableView{
    [self.myTableView registerNib:[UINib nibWithNibName:@"MessageCell" bundle:nil] forCellReuseIdentifier:cellID];
    self.myTableView.rowHeight = 215;
    [self.myTableView addNoteViewWithpicName:@"noDevice" noteText:@"" refreshBtnImg:nil orginY:120];
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 5;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    MessageCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    return cell;
}



@end
