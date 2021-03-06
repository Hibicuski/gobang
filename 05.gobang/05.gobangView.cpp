
// 05.gobangView.cpp : CMy05gobangView 窃議糞��
//

#include "stdafx.h"
// SHARED_HANDLERS 辛參壓糞�嶬だ澄∨�待夕才朴沫標僉匂鞘凹議
// ATL �酊訊仆�佩協吶��旺塋俯嚥乎�酊森河輓諜鬼�鷹。
#ifndef SHARED_HANDLERS
#include "05.gobang.h"
#endif

#include "05.gobangDoc.h"
#include "05.gobangView.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;


// CMy05gobangView

IMPLEMENT_DYNCREATE(CMy05gobangView, CView)

BEGIN_MESSAGE_MAP(CMy05gobangView, CView)
	// 炎彈嬉咫凋綜
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy05gobangView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_EDIT_UNDO, &CMy05gobangView::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CMy05gobangView::OnUpdateEditUndo)
	ON_COMMAND(ID_OPTION_OPTION, &CMy05gobangView::OnOptionGreen)
	ON_UPDATE_COMMAND_UI(ID_OPTION_OPTION, &CMy05gobangView::OnUpdateOptionGreen)
	ON_COMMAND(ID_OPTION_BLUE, &CMy05gobangView::OnOptionBlue)
	ON_UPDATE_COMMAND_UI(ID_OPTION_BLUE, &CMy05gobangView::OnUpdateOptionBlue)
	ON_COMMAND(ID_OPTION_YELLOW, &CMy05gobangView::OnOptionYellow)
	ON_UPDATE_COMMAND_UI(ID_OPTION_YELLOW, &CMy05gobangView::OnUpdateOptionYellow)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SCRL, &CMy05gobangView::OnUpdateTip)
	ON_COMMAND(ID_FILE_NEW1, &CMy05gobangView::OnFileNew)

	ON_COMMAND(IDB_BTN1, &CMy05gobangView::OnNewGameBtn)
	ON_COMMAND(IDB_BTN2, &CMy05gobangView::OnRollbackBtn)
	ON_UPDATE_COMMAND_UI(IDB_BTN2, &CMy05gobangView::OnRollback)
	ON_COMMAND(IDB_BTN3, &CMy05gobangView::OnSaveGameBtn)
	ON_COMMAND(IDB_BTN4, &CMy05gobangView::OnOpenGameBtn)
	ON_COMMAND(IDB_BTN5, &CMy05gobangView::OnOptionsBtn)
	ON_UPDATE_COMMAND_UI(IDB_BTN5, &CMy05gobangView::OnOptions)
	ON_COMMAND(IDB_BTN6, &CMy05gobangView::OnAboutGameBtn)
	
	ON_WM_CREATE()
END_MESSAGE_MAP()

//喘噐隠贋薙徒貧議泣議彜蓑
	int CMy05gobangView::ellipse[15][15] =
							{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
	bool CMy05gobangView::isEditUndoClick = false;
	bool CMy05gobangView::isSaveGameClick = false;
	int CMy05gobangView::mColor = 0;
	int CMy05gobangView::GREEN = 0;
	int CMy05gobangView::BLUE = 1;
	int CMy05gobangView::YELLOW = 2;
	bool CMy05gobangView::whitefirst = true;
	int CMy05gobangView::m1 = 0;
	int CMy05gobangView::m2 = 0;
	int CMy05gobangView::n1 = 0;
	int CMy05gobangView::n2 = 0;

// CMy05gobangView 更夛/裂更

bool bWin = false;
bool wWin = false;
int backgroundColor = 1;
CMy05gobangView::CMy05gobangView()
{
	// TODO: 壓緩侃耶紗更夛旗鷹
}

CMy05gobangView::~CMy05gobangView()
{
}

BOOL CMy05gobangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 壓緩侃宥狛俐個
	//  CREATESTRUCT cs 栖俐個完笥窃賜劔塀

	return CView::PreCreateWindow(cs);
}

// CMy05gobangView 紙崙

void CMy05gobangView::OnDraw(CDC* /*pDC*/)
{
	CMy05gobangDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 壓緩侃葎云字方象耶紗紙崙旗鷹
	AfxGetMainWnd()->SetWindowText(_T("励徨薙"));
}


// CMy05gobangView 嬉咫


void CMy05gobangView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy05gobangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 潮範彈姥
	return DoPreparePrinting(pInfo);
}

void CMy05gobangView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 耶紗駆翌議嬉咫念序佩議兜兵晒狛殻
}

void CMy05gobangView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 耶紗嬉咫朔序佩議賠尖狛殻
}

void CMy05gobangView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy05gobangView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy05gobangView 寶僅

#ifdef _DEBUG
void CMy05gobangView::AssertValid() const
{
	CView::AssertValid();
}

void CMy05gobangView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy05gobangDoc* CMy05gobangView::GetDocument() const // 掲距編井云頁坪選議
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy05gobangDoc)));
	return (CMy05gobangDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy05gobangView ��連侃尖殻會


void CMy05gobangView::OnPaint()
{
	// 音勣葎紙崙��連遇距喘 CWnd::OnPaint()
	 SetWindowPos(NULL,0,0,800,630,SWP_NOMOVE);
	 CPaintDC dc(this); // 喘噐紙崙議譜姥貧和猟
	 CRect   rect;  
	 GetClientRect(rect);  
	 switch(mColor)
	{
		case 0:
			{
				  dc.FillSolidRect(rect,RGB(0,255,0));
			}
			 break;
		 case 1:
			 {
				  dc.FillSolidRect(rect,RGB(0,0,255));
			 }
			 break;
		 case 2:
			 {
				   dc.FillSolidRect(rect,RGB(255,255,0));
			 }
			 break;
		 default:
			 break;
	} 
	 CClientDC cdc(this);
	 for(int i = 40;i <= 600;i = i + 40)
	 {
		cdc.MoveTo(40,i);
		cdc.LineTo(600,i);
		cdc.MoveTo(i,40);
	    cdc.LineTo(i,600);
	 }
	 CDC *pDC;
	 pDC = GetDC();
	 CBrush brush;
	 brush.CreateSolidBrush(RGB(0,0,0));
	 CBrush *pOldBrush;
	 CBrush brush2;
	 brush2.CreateSolidBrush(RGB(255,255,255));
	 CBrush *pOldBrush2;
	 for(int j =0;j < 15;j++)
	 {
		for(int m = 0;m <15 ;m++)
		{
			if(ellipse[j][m] == 1)
			{
				pOldBrush = pDC->SelectObject(&brush);
				pDC->Ellipse(j*40-15,m*40-15,j*40+15,m*40+15);
				pDC->SelectObject(pOldBrush);
			}else if(ellipse[j][m] == -1){
				pOldBrush2 = pDC->SelectObject(&brush2);
				pDC->Ellipse(j*40-15,m*40-15,j*40+15,m*40+15);
				pDC->SelectObject(pOldBrush2);
			}
		}
	 }
}

void CMy05gobangView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 壓緩耶紗��連侃尖殻會旗鷹才/賜距喘潮範峙

	while(bWin)
	{
		::MessageBox(NULL,_T("Black Win!"),_T("Game Over"),MB_OK);
		return;
	}
	while(wWin)
	{
		::MessageBox(NULL,_T("White Win!"),_T("Game Over"),MB_OK);
		return;
	}
	CDC *pDC;
	pDC = GetDC();
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,0));
	CBrush *pOldBrush;
	CBrush brush2;
	brush2.CreateSolidBrush(RGB(255,255,255));
	CBrush *pOldBrush2;
	int _x = point.x - (point.x%40);
	int _y = point.y - (point.y%40);
	if(point.x%40>20)
	{
		_x = _x + 40;
	}
	if(point.y%40>20)
	{
		_y = _y + 40;
	}
	int _m = _x/40;
	int _n = _y/40;
	if(point.x>20 && point.x < 620 &&point.y>20 && point.y<620)
	{

		if(whitefirst && ellipse[_m][_n]==0)
		{
			//易薙紙崙
			pOldBrush2 = pDC->SelectObject(&brush2);
			pDC->Ellipse(_x-15,_y-15,_x+15,_y+15);
			pDC->SelectObject(pOldBrush2);
			ellipse[_m][_n] = -1;
			m2 = _m;
			n2 = _n;
			whitefirst = false;
		}else if(!whitefirst && ellipse[_m][_n]==0){
			//菜薙紙崙	
			pOldBrush = pDC->SelectObject(&brush);
			pDC->Ellipse(_x-15,_y-15,_x+15,_y+15);
			pDC->SelectObject(pOldBrush);
			ellipse[_m][_n] = 1;
			m1=_m;
			n1 = _n;
			whitefirst = true;
		}
	}
	if((m1 != 0 && n1 !=0) || (m2 !=0 && n2 != 0))
	{
		isEditUndoClick = false;
		isSaveGameClick = true;
	}
	vertial(_m,_n);
	horizontal(_m,_n);
	left(_m,_n);
	right(_m,_n);
}

void CMy05gobangView::vertial(int x,int y)
{
	
	int top = (y - 4) >= 0 ? (y - 4) : 0;
	int bottom = (y + 4) <= 15 ? (y + 4) : 15;
	for (top; top < bottom - 4; top++) {
		int total = ellipse[x][top] + ellipse[x][top + 1] + 
			ellipse[x][top + 2]+ ellipse[x][top + 3] + ellipse[x][top + 4];
		if (total == 5) {
			::MessageBox(NULL, _T("菜薙資覆!"), _T("嗄老潤崩"), MB_OK);
			bWin = true;
			return;
		}
		else if (total == -5) {
			::MessageBox(NULL, _T("易薙資覆!"), _T("嗄老潤崩"), MB_OK);
			wWin = true;
			return;
		}
	}
}
void CMy05gobangView::horizontal(int x,int y)
{
	int left = (x - 4) >= 0 ? (x - 4) : 0;
	int right = (x + 4) <= 15 ? (x + 4) : 15;
	for (left; left <= right - 4; left++) {
		int total = ellipse[left][y] + ellipse[left + 1][y] +
			ellipse[left + 2][y] + ellipse[left + 3][y] + ellipse[left + 4][y];
		if (total == 5) {
			::MessageBox(NULL, _T("菜薙資覆!"), _T("嗄老潤崩"), MB_OK);
			bWin = true;
			return;
		}
		else if (total == -5) {
			::MessageBox(NULL, _T("易薙資覆!"), _T("嗄老潤崩"), MB_OK);
			wWin = true;
			return;
		}
	}
}
void CMy05gobangView::left(int x,int y)
{
	int top = (y - 4) >= 0 ? (y - 4) : 0;
	int bottom = (y + 4) <= 15 ? (y + 4) : 15;
	int left = (x - 4) >= 0 ? (x - 4) : 0;
	int right = (x + 4) <= 15 ? (x + 4) : 15;
	if (x - left > y - top) {
		left = x - (y - top);
	}
	else {
		top = y - (x - left);
	}

	if (right - x > bottom - y) {
		right = x + bottom - y;
	}
	else {
		bottom = y + right - x;
	}
	for (left;left <= right - 4; left++) {
		int total = ellipse[left][top] + ellipse[left + 1][top + 1] +
			ellipse[left + 2][top + 2] + ellipse[left + 3][top + 3] +
			ellipse[left + 4][top + 4];
		top++;
		if (total == 5) {
			::MessageBox(NULL, _T("菜薙資覆!"), _T("嗄老潤崩"), MB_OK);
			bWin = true;
			return;
		}
		else if (total == -5) {
			::MessageBox(NULL, _T("易薙資覆!"), _T("嗄老潤崩"), MB_OK);
			wWin = true;
			return;
		}
	}
}
void CMy05gobangView::right(int x,int y)
{
	int top = (y - 4) >= 0 ? (y - 4) : 0;
	int bottom = (y + 4) <= 15 ? (y + 4) : 15;
	int left = (x - 4) >= 0 ? (x - 4) : 0;
	int right = (x + 4) <= 15 ? (x + 4) : 15;
	if (x - left > y - top) {
		left = x - (y - top);
	}
	else {
		top = y - (x - left);
	}

	if (right - x > bottom - y) {
		right = x + bottom - y;
	}
	else {
		bottom = y + right - x;
	}
	for (left;left < right - 4; left++) {
		int total = ellipse[left][bottom] + ellipse[left + 1][bottom - 1] +
			ellipse[left + 2][bottom - 2] + ellipse[left + 3][bottom - 3] +
			ellipse[left + 4][bottom - 4];
		bottom--;
		if (total == 5) {
			::MessageBox(NULL, _T("菜薙資覆!"), _T("嗄老潤崩"), MB_OK);
			bWin = true;
			return;
		}
		else if (total == -5) {
			::MessageBox(NULL, _T("易薙資覆!"), _T("嗄老潤崩"), MB_OK);
			wWin = true;
			return;
		}
	}
}


void CMy05gobangView::OnEditUndo()
{
	// TODO: 壓緩耶紗凋綜侃尖殻會旗鷹
	ellipse[m1][n1] = 0;
	ellipse[m2][n2] = 0;
	isEditUndoClick = true;
	int sum = 0;
	for(int j =0;j < 15;j++)
	{
		for(int m = 0;m <15 ;m++)
		{
			sum += abs(ellipse[j][m]);
		}
	}
	if(sum == 0)
	{
		whitefirst = true;
	}
	Invalidate();
}

BOOL CMy05gobangView::isChessChange()
{
	if(bWin || wWin || isEditUndoClick)
	{
		return false;
	}
	int sum = 0;
	for(int j =0;j < 15;j++)
	{
		for(int m = 0;m <15 ;m++)
		{
			sum += abs(ellipse[j][m]);
		}
	}
	if(sum == 0)
	{
		return false;
	}
	if((m1 != 0 && n1 !=0) || (m2 !=0 && n2 != 0))
	{
		return true;
	}
	return false;
}

void CMy05gobangView::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO: 壓緩耶紗凋綜厚仟喘薩順中侃尖殻會旗鷹
	pCmdUI->Enable(isChessChange());
}

void CMy05gobangView::OnOptionGreen()
{
	// TODO: 壓緩耶紗凋綜侃尖殻會旗鷹
	mColor = GREEN;
	Invalidate(TRUE);
}


void CMy05gobangView::OnUpdateOptionGreen(CCmdUI *pCmdUI)
{
	// TODO: 壓緩耶紗凋綜厚仟喘薩順中侃尖殻會旗鷹
	pCmdUI ->SetCheck(mColor == GREEN);
	pCmdUI->Enable(mColor != GREEN);
}


void CMy05gobangView::OnOptionBlue()
{
	// TODO: 壓緩耶紗凋綜侃尖殻會旗鷹
	mColor = BLUE;
	Invalidate(TRUE);
}


void CMy05gobangView::OnUpdateOptionBlue(CCmdUI *pCmdUI)
{
	// TODO: 壓緩耶紗凋綜厚仟喘薩順中侃尖殻會旗鷹
	pCmdUI ->SetCheck(mColor == BLUE);
	pCmdUI->Enable(mColor != BLUE);
}


void CMy05gobangView::OnOptionYellow()
{
	// TODO: 壓緩耶紗凋綜侃尖殻會旗鷹
	mColor = YELLOW;
	Invalidate(TRUE);
}


void CMy05gobangView::OnUpdateOptionYellow(CCmdUI *pCmdUI)
{
	// TODO: 壓緩耶紗凋綜厚仟喘薩順中侃尖殻會旗鷹
	pCmdUI ->SetCheck(mColor == YELLOW);
	pCmdUI->Enable(mColor != YELLOW);
}

void CMy05gobangView::OnUpdateTip(CCmdUI *pCmdUI)
{
	if(whitefirst)
	{
		pCmdUI->SetText(_T("White"));
	}else if(!whitefirst){
		pCmdUI->SetText(_T("Black"));	
	}
}

void CMy05gobangView::OnFileNew()
{
	// TODO: 壓緩耶紗凋綜侃尖殻會旗鷹
	for(int i = 0;i < 15;i++)
	{
		for(int j = 0;j < 15;j++)
		{
			ellipse[i][j] = 0;
		}
	}
	bWin = false;
	wWin = false;
	whitefirst = true;
	Invalidate();
}


int CMy05gobangView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  壓緩耶紗艇廨喘議幹秀旗鷹
	PlaySound(TEXT("消墳斑 (ひさいし じょう) _ ロンドン住���S�� - Summer.wav"), NULL, SND_FILENAME | SND_ASYNC);


	//仟嗄老
	CRect rect1(640, 120, 740, 160);
	new_game.Create(_T("仟嗄老"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect1, this, IDB_BTN1);
	
	//隠贋嗄老
	CRect rect2(640, 180, 740, 220);
	rollback.Create(_T("孜薙"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect2, this, IDB_BTN2);

	//隠贋嗄老
	CRect rect3(640, 240, 740, 280);
	save_game.Create(_T("隠贋嗄老"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect3, this, IDB_BTN3);

	//嬉蝕嗄老
	CRect rect4(640, 300, 740, 340);
	open_game.Create(_T("嬉蝕嗄老"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect4, this, IDB_BTN4);

	//厚算嘘尚
	CRect rect5(640, 360, 740, 400);
	options.Create(_T("厚算嘘尚"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect5, this, IDB_BTN5);

	//購噐嗄老
	CRect rect6(640, 420, 740, 460);
	about_game.Create(_T("購噐嗄老"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect6, this, IDB_BTN6);

	new_game.ShowWindow(SW_SHOWNORMAL);
	rollback.ShowWindow(SW_SHOWNORMAL);
	save_game.ShowWindow(SW_SHOWNORMAL);
	open_game.ShowWindow(SW_SHOWNORMAL);
	options.ShowWindow(SW_SHOWNORMAL);
	about_game.ShowWindow(SW_SHOWNORMAL);

	return 0;
}

//仟嗄老
void CMy05gobangView::OnNewGameBtn() {
	for (int i = 0;i < 15;i++)
	{
		for (int j = 0;j < 15;j++)
		{
			ellipse[i][j] = 0;
		}
	}
	bWin = false;
	wWin = false;
	whitefirst = true;
	Invalidate();
}

//孜薙
void CMy05gobangView::OnRollback(CCmdUI *pCmdUI) {
	pCmdUI->Enable(isChessChange());
}

void CMy05gobangView::OnRollbackBtn() {
	if (whitefirst) {
		ellipse[m2][n2] = 0;
		whitefirst = false;
	}
	else {
		ellipse[m1][n1] = 0;
		whitefirst = true;
	}
	isEditUndoClick = true;
	int sum = 0;
	for (int j = 0;j < 15;j++)
	{
		for (int m = 0;m <15;m++)
		{
			sum += abs(ellipse[j][m]);
		}
	}
	if (sum == 0)
	{
		whitefirst = true;
	}
	Invalidate();
}

void CMy05gobangView::OnSaveGameBtn() {

}

void CMy05gobangView::OnOpenGameBtn() {

}

void CMy05gobangView::OnOptions(CCmdUI *pCmdUI) {
	//backgroundColor方峙葎1扮俳算葎駄弼
	if (backgroundColor == 1) {
		pCmdUI->SetCheck(mColor == GREEN);
		pCmdUI->Enable(mColor != GREEN);
		backgroundColor = 2;
	}
	//backgroundColor方峙葎2扮俳算葎清弼
	else if (backgroundColor == 2) {
		pCmdUI->SetCheck(mColor == BLUE);
		pCmdUI->Enable(mColor != BLUE);
		backgroundColor = 3;
	}
	//backgroundColor方峙葎3扮俳算葎仔弼
	else if (backgroundColor == 3) {
		pCmdUI->SetCheck(mColor == YELLOW);
		pCmdUI->Enable(mColor != YELLOW);
		backgroundColor = 1;
	}
}

void CMy05gobangView::OnOptionsBtn() {
	//backgroundColor方峙葎1扮俳算葎駄弼
	if (backgroundColor == 1) {
		mColor = GREEN;
		Invalidate(TRUE);
		backgroundColor = 2;
	}
	//backgroundColor方峙葎2扮俳算葎清弼
	else if (backgroundColor == 2) {
		mColor = BLUE;
		Invalidate(TRUE);
		backgroundColor = 3;
	}
	//backgroundColor方峙葎3扮俳算葎仔弼
	else if (backgroundColor == 3) {
		mColor = YELLOW;
		Invalidate(TRUE);
		backgroundColor = 1;
	}
}
void CMy05gobangView::OnAboutGameBtn() {

	
	theApp.OnAppAbout();
}