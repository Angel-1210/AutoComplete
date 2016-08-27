//
//  MessageTableViewCell.h
//  Messenger
//
//  Created by Ignacio Romero Zurbuchen on 9/1/14.
//  Copyright (c) 2014 Slack Technologies, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ResponsiveLabel.h"

static CGFloat kMessageTableViewCellMinimumHeight = 80.0;
static CGFloat kMessageTableViewCellAvatarHeight = 60.0;

static NSString *MessengerCellIdentifier = @"MessengerCell";
static NSString *AutoCompletionCellIdentifier = @"AutoCompletionCell";

@protocol CustomTableViewCellDelegate;

@interface MessageTableViewCell : UITableViewCell

@property (nonatomic, weak) id<CustomTableViewCellDelegate>delegate;

@property (nonatomic, strong) ResponsiveLabel *titleLabel;
@property (nonatomic, strong) UILabel *bodyLabel;
@property (nonatomic, strong) UIImageView *thumbnailView;

@property (nonatomic, strong) NSIndexPath *indexPath;

@property (nonatomic) BOOL usedForMessage;

+ (CGFloat)defaultFontSize;

@end

@protocol CustomTableViewCellDelegate<NSObject>

@optional

- (void)didTapOnMoreButton:(MessageTableViewCell *)cell;
- (void)customTableViewCell:(MessageTableViewCell *)cell didTapOnHashTag:(NSString *)hashTag;
- (void)customTableViewCell:(MessageTableViewCell *)cell didTapOnUserHandle:(NSString *)userHandle;
- (void)customTableViewCell:(MessageTableViewCell *)cell didTapOnURL:(NSString *)urlString;

@end
