//
//  HelpViewController.m
//  m2mSecurity
//
//  Created by chendan on 2021/8/16.
//

#import "HelpViewController.h"
#import "HelpCell.h"

@interface HelpViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *myTableView;

@end

static NSString *cellID = @"cellId";
@implementation HelpViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.navigationItem.title = @"帮助中心";
    
    [self.myTableView registerNib:[UINib nibWithNibName:@"HelpCell" bundle:nil] forCellReuseIdentifier:cellID];
    self.myTableView.rowHeight = 57;
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 4;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    HelpCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    return cell;
}



@end
