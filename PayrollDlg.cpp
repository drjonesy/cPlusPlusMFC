
// PayrollDlg.cpp : implementation file
//


#include "stdafx.h"
#include "Payroll.h"
#include "PayrollDlg.h"
#include "afxdialogex.h"

#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPayrollDlg dialog



CPayrollDlg::CPayrollDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAYROLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPayrollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPayrollDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnProcessIt, &CPayrollDlg::OnBnClickedbtnprocessit)
END_MESSAGE_MAP()


// CPayrollDlg message handlers

BOOL CPayrollDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPayrollDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPayrollDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPayrollDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPayrollDlg::OnBnClickedbtnprocessit()
{
	CString textInput;
	//Employee ID
	GetDlgItemText(txtEmployeeID, textInput);
	double dEmployeeId = _ttof(textInput);
	// Hourly Wage
	GetDlgItemText(txtHourlyWage, textInput);
	double dHourlyWage = _ttof(textInput);

	//First Week
	GetDlgItemText(txtFirstMonday, textInput);
	double dFirstMonday = _ttof(textInput);

	GetDlgItemText(txtFirstTuesday, textInput);
	double dFirstTuesday = _ttof(textInput);

	GetDlgItemText(txtFirstWednesday, textInput);
	double dFirstWednesday = _ttof(textInput);

	GetDlgItemText(txtFirstThursday, textInput);
	double dFirstThursday = _ttof(textInput);

	GetDlgItemText(txtFirstFriday, textInput);
	double dFirstFriday = _ttof(textInput);

	GetDlgItemText(txtFirstSaturday, textInput);
	double dFirstSaturday = _ttof(textInput);
	
	GetDlgItemText(txtFirstSunday, textInput);
	double dFirstSunday = _ttof(textInput);

	//Second Week
	GetDlgItemText(txtSecondMonday, textInput);
	double dSecondMonday = _ttof(textInput);

	GetDlgItemText(txtSecondTuesday, textInput);
	double dSecondTuesday = _ttof(textInput);

	GetDlgItemText(txtSecondWednesday, textInput);
	double dSecondWednesday = _ttof(textInput);

	GetDlgItemText(txtSecondThursday, textInput);
	double dSecondThursday = _ttof(textInput);

	GetDlgItemText(txtSecondFriday, textInput);
	double dSecondFriday = _ttof(textInput);

	GetDlgItemText(txtSecondSaturday, textInput);
	double dSecondSaturday = _ttof(textInput);

	GetDlgItemText(txtSecondSunday, textInput);
	double dSecondSunday = _ttof(textInput);

	// === Hours Calculations
	double week1Hours = 0;
	double week2Hours = 0;
	week1Hours = dFirstMonday + dFirstTuesday + dFirstWednesday + dFirstThursday + dFirstFriday + dFirstSaturday + dFirstSunday;
	week2Hours = dSecondMonday + dSecondTuesday + dSecondWednesday + dSecondThursday + dSecondFriday + dSecondSaturday + dSecondSunday;
	double regularHoursWeek1 = 0;
	double regularHoursWeek2 = 0;
	double totalHours = 0;
	double overtimeHoursWeek1 = 0;
	double overtimeHoursWeek2 = 0;
	double totalOvertime = 0;
	// === Amount Calculations: dHourlyWage
	double regularAmountPay = 0;
	double overtimeAmountPay = 0;
	double totalEarnings = 0;

	//get hours
	if (week1Hours > 40) {
		regularHoursWeek1 = 40;
		overtimeHoursWeek1 = week1Hours - 40;
	}
	else {
		regularHoursWeek1 = week1Hours;
	}
	if (week2Hours > 40) {
		regularHoursWeek2 = 40;
		overtimeHoursWeek2 = week2Hours - 40;
	}
	else {
		regularHoursWeek2 = week2Hours;
	}

	totalHours = regularHoursWeek1 + regularHoursWeek2;
	totalOvertime = overtimeHoursWeek1 + overtimeHoursWeek2;
	
	//get amounts
	regularAmountPay = dHourlyWage * totalHours;
	overtimeAmountPay = (dHourlyWage * 1.5) * totalOvertime;
	totalEarnings = regularAmountPay + overtimeAmountPay;

	//set regular hours
	string strTotalHours = to_string(totalHours);
	CString totalRegularHours(strTotalHours.c_str());
	SetDlgItemText(txtRegularHours, totalRegularHours);
	
	//set overtime hours
	string strTotalOvertimeHours = to_string(totalOvertime);
	CString totalOvertimeHours(strTotalOvertimeHours.c_str());
	SetDlgItemText(txtOvertimeHours, totalOvertimeHours);
	
	//set regular pay amount
	string strRegularAmount = to_string(regularAmountPay);
	CString totalRegularAmount(strRegularAmount.c_str());
	SetDlgItemText(txtRegularAmount, totalRegularAmount);

	//set overtime pay amount
	string strOvertimeAmount = to_string(overtimeAmountPay);
	CString totalOvertimeAmount(strOvertimeAmount.c_str());
	SetDlgItemText(txtOvertimeAmount, totalOvertimeAmount);

	//set total earnings
	string strTotalEarnings = to_string(totalEarnings);
	CString csTotalEarnings(strTotalEarnings.c_str());
	SetDlgItemText(txtTotalEarnings, csTotalEarnings);
}
