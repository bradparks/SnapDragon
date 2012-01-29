//
//  ResultsTableView.h
//
//  Created by Sveinbjorn Thordarson on 1/26/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Carbon/Carbon.h>
#import "NSTask+Description.m"
#import "NSFileManager+FileOrFolderSize.m"
#import <sys/stat.h>
#import "ResultItem.h"
#import "STPathTextField.h"
#import "Common.h"

@interface ResultsController: NSObject <NSTableViewDataSource, NSTableViewDelegate>
{
    NSMutableArray  *results;
    IBOutlet id     resultsTableView;
    IBOutlet id     window;
    IBOutlet id     contextualMenu;
    IBOutlet id     progressIndicator;
    IBOutlet id     locateButton;
    IBOutlet STPathTextField *queryTextField;
    IBOutlet id     filterTextField;
    IBOutlet id     numResultsTextField;
    
    NSTask          *task;    
    NSTimer         *checkStatusTimer;
    NSPipe          *outputPipe;
    NSFileHandle    *readHandle;
    BOOL            isTaskRunning;
    BOOL            outputEmpty;
    NSString        *remnants;
    UInt64          totalSize;

}
-(IBAction)locate: (id)sender;
- (void)addPath: (NSString *)path;
- (void)clear;
- (IBAction)open: (id)sender;
- (IBAction)openWith: (id)sender;
- (IBAction)showInFinder:(id)sender;
- (void)revealInFinder: (NSInteger)index;
- (void)openInFinder: (NSInteger)index;
- (IBAction)getInfo: (id)sender;
- (IBAction)copyFile: (id)sender;
- (IBAction)quickLook: (id)sender;
- (IBAction)setLabel:(id)sender;
- (IBAction)deleteFile:(id)sender;
- (IBAction)moveToTrash:(id)sender;
- (IBAction)openDirectoryInTerminal:(id)sender;
- (IBAction)runInTerminal:(id)sender;
- (void)updateNumFiles;
-(void)appendOutput: (NSData *)data;
-(void)getOutputData: (NSNotification *)aNotification;

@end
