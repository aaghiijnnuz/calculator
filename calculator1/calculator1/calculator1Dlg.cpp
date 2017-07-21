
// calculator1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator1.h"
#include "calculator1Dlg.h"
#include "afxdialogex.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.1415926535898

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Ccalculator1Dlg �Ի���



Ccalculator1Dlg::Ccalculator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR1_DIALOG, pParent)
{
	m_str = _T("");

	m_fNumber1 = 0.0f;
	m_fNumber2 = 0.0f;

	m_m = 0.0f;
	m_2 = 0;

	m_num = 10;

	m_symbol = 1;
	m_time = 0;
	m_number = 0;

	m_iSign = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccalculator1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(Ccalculator1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Ccalculator1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &Ccalculator1Dlg::OnMyAbout)
	ON_BN_CLICKED(IDC_BUTTON18, &Ccalculator1Dlg::OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON19, &Ccalculator1Dlg::OnButtonClearall)
	ON_BN_CLICKED(IDC_BUTTON2, &Ccalculator1Dlg::OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Ccalculator1Dlg::OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Ccalculator1Dlg::OnButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Ccalculator1Dlg::OnButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &Ccalculator1Dlg::OnButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &Ccalculator1Dlg::OnButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &Ccalculator1Dlg::OnButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &Ccalculator1Dlg::OnButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &Ccalculator1Dlg::OnButton9)
	ON_BN_CLICKED(IDC_BUTTON15, &Ccalculator1Dlg::OnButton0)
	ON_BN_CLICKED(IDC_BUTTON16, &Ccalculator1Dlg::OnButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON11, &Ccalculator1Dlg::OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON12, &Ccalculator1Dlg::OnButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON13, &Ccalculator1Dlg::OnButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON14, &Ccalculator1Dlg::OnButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON17, &Ccalculator1Dlg::OnButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON27, &Ccalculator1Dlg::OnButtonMod)
	ON_BN_CLICKED(IDC_BUTTON20, &Ccalculator1Dlg::OnButtonSquare)
	ON_BN_CLICKED(IDC_BUTTON26, &Ccalculator1Dlg::OnButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON32, &Ccalculator1Dlg::OnButtonPrecent)
	ON_BN_CLICKED(IDC_BUTTON33, &Ccalculator1Dlg::OnButtonReciprocal)
	ON_BN_CLICKED(IDC_BUTTON21, &Ccalculator1Dlg::OnButtonPositive_or_negative)
	ON_BN_CLICKED(IDC_BUTTON34, &Ccalculator1Dlg::OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON28, &Ccalculator1Dlg::OnButtonMS)
	ON_BN_CLICKED(IDC_BUTTON29, &Ccalculator1Dlg::OnButtonMR)
	ON_BN_CLICKED(IDC_BUTTON30, &Ccalculator1Dlg::OnButtonMC)
	ON_BN_CLICKED(IDC_BUTTON25, &Ccalculator1Dlg::OnButtonMadd)
	ON_BN_CLICKED(IDC_BUTTON31, &Ccalculator1Dlg::OnButtonMminus)
	ON_BN_CLICKED(IDC_BUTTON22, &Ccalculator1Dlg::OnButtonSin)
	ON_BN_CLICKED(IDC_BUTTON23, &Ccalculator1Dlg::OnButtonCos)
	ON_BN_CLICKED(IDC_BUTTON24, &Ccalculator1Dlg::OnButtonTan)
	ON_BN_CLICKED(IDC_BUTTON35, &Ccalculator1Dlg::OnButton00)
	ON_BN_CLICKED(IDC_BUTTON36, &Ccalculator1Dlg::OnButtonPI)
	ON_BN_CLICKED(IDC_BUTTON37, &Ccalculator1Dlg::OnButtonN)
	ON_BN_CLICKED(IDC_BUTTON38, &Ccalculator1Dlg::OnButtonX_Y)
	ON_BN_CLICKED(IDC_BUTTON39, &Ccalculator1Dlg::OnButtonLog)
	ON_BN_CLICKED(IDC_BUTTON40, &Ccalculator1Dlg::OnButtonLn)
	ON_BN_CLICKED(IDC_BUTTON41, &Ccalculator1Dlg::OnButtonNot)
	ON_BN_CLICKED(IDC_BUTTON42, &Ccalculator1Dlg::OnButtonAnd)
	ON_BN_CLICKED(IDC_RADIO1, &Ccalculator1Dlg::OnRadioChange_2)
	ON_COMMAND(ID_FINE_ABOUT, &Ccalculator1Dlg::OnFineClose)
	ON_BN_CLICKED(IDC_RADIO2, &Ccalculator1Dlg::OnRadioChange_10)
	ON_COMMAND(ID_HELP_ABOUT, &Ccalculator1Dlg::OnHelpAbout)
	ON_BN_CLICKED(IDC_BUTTON43, &Ccalculator1Dlg::OnButtonOr)
	ON_BN_CLICKED(IDC_BUTTON44, &Ccalculator1Dlg::OnButtonXol)
END_MESSAGE_MAP()


// Ccalculator1Dlg ��Ϣ�������

BOOL Ccalculator1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	CMenu menu;//����һ���˵������
	menu.LoadMenu(IDR_MENU1);//װ��IDR_MENU1�˵���Դ
	SetMenu(&menu);//�͵�ǰ���ڹ�������
	menu.Detach();//����

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Ccalculator1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ccalculator1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ccalculator1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccalculator1Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




void Ccalculator1Dlg::OnMyAbout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg dlg;
	dlg.DoModal();
}


void Ccalculator1Dlg::OnButtonBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//�Ƴ����ұ�һ���ַ�
	if (!m_str.IsEmpty())
	{
		m_str = m_str.Left(m_str.GetLength() - 1);
	}
	UpdateData(FALSE);
}



void Ccalculator1Dlg::OnButtonClearall()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_str = "";
	m_fNumber1 = 0.0f;
	m_fNumber2 = 0.0f;
	m_iSign = 0;
	m_symbol = 1;
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"1";
		m_number++;
	}
	else
		m_str = m_str + (CString)"1";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"2";
		m_number++;
	}
	else
		m_str = m_str + (CString)"2";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"3";
		m_number++;
	}
	else
		m_str = m_str + (CString)"3";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"4";
		m_number++;
	}
	else
		m_str = m_str + (CString)"4";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"5";
		m_number++;
	}
	else
		m_str = m_str + (CString)"5";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"6";
		m_number++;
	}
	else
		m_str = m_str + (CString)"6";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"7";
		m_number++;
	}
	else
		m_str = m_str + (CString)"7";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"8";
		m_number++;
	}
	else
		m_str = m_str + (CString)"8";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && -1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"9";
		m_number++;
	}
	else
		m_str = m_str + (CString)"9";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (_wtof(m_str.GetBuffer(0)) == 0 && - 1 == m_str.Find('.') && m_str == 1)
	{
		m_number = 0;
	}
	if ( m_number == 0)
	{
		m_str = (CString)"0";
		m_number++;
	}
	else
		m_str = m_str + (CString)"0";
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//���û��С���㣬�����һ��С���㣬�������С����ͺ��Դ˴ε�С���㣬��֤���ֻ��1��
	if (-1 == m_str.Find('.'))
	{
		m_str = m_str + (CString)".";
	}
	UpdateData(FALSE);
}

void Ccalculator1Dlg::SaveValue1()
{
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	m_str = "";
}

void Ccalculator1Dlg::OnButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_time++;
	m_number = 0;
	if (m_time > 1)
		Calculator();
	else
	{
		SaveValue1();
	}
	m_iSign = 1;
}


void Ccalculator1Dlg::OnButtonMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_time++;
	m_number = 0;
	if (m_time > 1)
		Calculator();
	else
	{
		SaveValue1();
	}
	m_iSign = 2;
}


void Ccalculator1Dlg::OnButtonMultiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_time++;
	m_number = 0;
	if (m_time > 1)
		Calculator();
	else
	{
		SaveValue1();
	}
	m_iSign = 3;
}


void Ccalculator1Dlg::OnButtonDivide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_time++;
	m_number = 0;
	if (m_time > 1)
	{
		Calculator();
	}
	else
	{
		SaveValue1();
	}
	m_iSign = 4;
}

void Ccalculator1Dlg::Calculator()
{
	UpdateData(TRUE);
	m_fNumber2 = _wtof(m_str.GetBuffer(0));
	double f = 0.0f;
	int x, y;
	int z = 0;
	switch (m_iSign)
	{
		//û������
	case 0:
		SaveValue1();
		f = m_fNumber1;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//��
	case 1:
		f = m_fNumber1 + m_fNumber2;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//��
	case 2:
		f = m_fNumber1 - m_fNumber2;
		if (f < 0)
		{
			m_symbol = -1;
		}
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//��
	case 3:
		f = m_fNumber1 * m_fNumber2;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//��
	case 4:
		if (m_fNumber2 == 0.0f)
		{
			m_str = (CString)"MATH ERROR";
			f = m_fNumber1;
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			f = m_fNumber1 / m_fNumber2;
			str_to_double(f);
			m_fNumber1 = f;
			m_fNumber2 = 0.0f;
		}
		break;
		//ƽ��
	case 5:
		f = m_fNumber2 * m_fNumber2;
		m_symbol = 1;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//����
	case 6:
		f = sqrt(m_fNumber2);
		if (f < 0)
		{
			m_str = (CString)"MATH ERROR";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			str_to_double(f);
			m_fNumber1 = f;
			m_fNumber2 = 0.0f;
		}
		break;
		//����
	case 7:
		f = m_fNumber2;
		if (f == 0)
		{
			m_str = (CString)"MATH ERROR";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			f = 1 / m_fNumber2;
			str_to_double(f);
			m_fNumber1 = f;
			m_fNumber2 = 0.0f;
		}
		break;
		//x^y
	case 8:
			f = pow(m_fNumber1, m_fNumber2);
			str_to_double(f);
			m_fNumber1 = f;
			m_fNumber2 = 0.0f;
		break;
		//ȡģ
	case 9:
		f = (int)m_fNumber1 % (int)m_fNumber2;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		break;
		//AND
	case 10:
		if (m_num == 10)
		{
			m_str = (CString)"WRONG OPERATION";
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			x = (int)m_fNumber1;
			y = (int)m_fNumber2;
			if (m_2 >  m_str.GetLength())
			{
				for (int i = 0, j = 1; i < m_2; i++)
				{
					if (x % 10 == 1 && y % 10 == 1)
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			else
			{
				for (int i = 0, j = 1; i < m_str.GetLength(); i++)
				{
					if (x % 10 == 1 && y % 10 == 1)
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			str_to_double(z);
			m_fNumber1 = z;
			m_fNumber2 = 0.0f;
			m_2 = 0;
			m_iSign = 0;
		}
		break;
		//OR
	case 11:
		if (m_num == 10)
		{
			m_str = (CString)"WRONG OPERATION";
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			x = (int)m_fNumber1;
			y = (int)m_fNumber2;
			if (m_2 >  m_str.GetLength())
			{
				for (int i = 0, j = 1; i < m_2; i++)
				{
					if (x % 10 == 1 || y % 10 == 1)
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			else
			{
				for (int i = 0, j = 1; i < m_str.GetLength(); i++)
				{
					if (x % 10 == 1 || y % 10 == 1)
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			str_to_double(z);
			m_fNumber1 = z;
			m_fNumber2 = 0.0f;
			m_2 = 0;
			m_iSign = 0;
		}
		break;
		//XOL
	case 12:
		if (m_num == 10)
		{
			m_str = (CString)"WRONG OPERATION";
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			x = (int)m_fNumber1;
			y = (int)m_fNumber2;
			if (m_2 >  m_str.GetLength())
			{
				for (int i = 0, j = 1; i < m_2; i++)
				{
					if (x % 10  != y % 10 )
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			else
			{
				for (int i = 0, j = 1; i < m_str.GetLength(); i++)
				{
					if (x % 10  != y % 10 )
					{
						z += j;
					}
					j *= 10;
					x /= 10;
					y /= 10;
				}
			}
			str_to_double(z);
			m_fNumber1 = z;
			m_fNumber2 = 0.0f;
			m_2 = 0;
			m_iSign = 0;
		}
		break;
	default:
		break;
	}

	UpdateData(FALSE);

	m_number = 0;

}

void Ccalculator1Dlg::OnButtonEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculator();
	m_time = 0;
	m_number = 0;
}


void Ccalculator1Dlg::OnButtonMod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_time++;
	m_number = 0;
	if (m_time > 1)
		Calculator();
	else
	{
		SaveValue1();
	}
	m_iSign = 9;
}


void Ccalculator1Dlg::OnButtonSquare()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	double f = m_fNumber1 * m_fNumber1;
	m_symbol = 1;
	str_to_double(f);
	
	UpdateData(FALSE);

	m_fNumber1 = f;
	m_fNumber2 = 0.0f;

	m_number = 0;
	m_iSign = 5;
}


void Ccalculator1Dlg::OnButtonSqrt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	if (m_symbol == -1)
	{

		m_str = (CString)"MATH ERROR";
		m_number = 0;
		m_time = 0;
		m_symbol = 1;
		UpdateData(FALSE);
	}
	else
	{

		double f = sqrt(m_fNumber1);
		str_to_double(f);
		
		UpdateData(FALSE);

		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		m_number = 0;

		m_iSign = 6;
	}
}


void Ccalculator1Dlg::OnButtonPrecent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber2 = _wtof(m_str.GetBuffer(0));
	double f = m_fNumber2*m_fNumber1/100;
	str_to_double(f);
	UpdateData(FALSE);
	m_number = 0;
	m_fNumber2 = f;
}


void Ccalculator1Dlg::OnButtonReciprocal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	if (m_fNumber1 == 0)
	{
		m_str = (CString)"MATH ERROR";
		m_number = 0;
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		double f = 1 / m_fNumber1;
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
		m_iSign = 7;
		m_number = 0;
	}
	
	UpdateData(FALSE);

}


void Ccalculator1Dlg::OnButtonPositive_or_negative()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_symbol == 1)
	{
		m_symbol = -1;
		if (m_number == 0)
		{
			m_str = (CString)"-" ;
		}
		else
		{
			m_str = (CString)"-" + m_str;
		}
		m_number++;
	}
	else
	{
		m_symbol = 1;
		m_str.Remove(m_str[0]);
	}
	UpdateData(FALSE);
}

void Ccalculator1Dlg::str_to_double(double f)
{
	if (m_symbol == 1)
	{
		//�����������ʵ�Ǹ�����
		if ( f - int(f) <= 1e-5)
		{
			m_str.Format(_T("%d"), (int)f);
		}
		else
		{
			m_str.Format(_T("%f"), f);
			if (m_str.Find('.') != -1)
			{
				int count = 0;
				for (int i = 0; i < m_str.GetLength(); i++)
				{
					if (i == m_str.Find('0', i))
						count++;
					else
					{
						count = 0;
					}
				}
				m_str = m_str.Left((m_str.GetLength() - count));
			}
		}
	}
	else
	{
		//�����������ʵ�Ǹ�����
		if ((-f - int(f)) <= 1e-5)
		{
			m_str.Format(_T("%d"), -(int)f);
		}
		else
		{
			m_str.Format(_T("%f"), f);
			int count = 0;
			for (int i = 0; i < m_str.GetLength(); i++)
			{
				if (i == m_str.Find('0', i))
					count++;
				else
				{
					count = 0;
				}
			}
			m_str = m_str.Left((m_str.GetLength() - count));
		}
	}
}

void Ccalculator1Dlg::OnButtonClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_str = "";
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonMS()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_m = _wtof(m_str.GetBuffer(0));
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonMR()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	str_to_double(m_m);
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonMC()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_m = 0;
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonMadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_m += _wtof(m_str.GetBuffer(0));
	str_to_double(m_m);
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonMminus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_m -= _wtof(m_str.GetBuffer(0));
	str_to_double(m_m);
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonSin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	double f = sin(m_fNumber1 * PI / 180);
	str_to_double(f);

	m_number = 0;

	UpdateData(FALSE);

	m_fNumber1 = f;
	m_fNumber2 = 0.0f;

}


void Ccalculator1Dlg::OnButtonCos()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	double f = cos(m_fNumber1 * PI / 180);
	str_to_double(f);

	m_number = 0;

	UpdateData(FALSE);

	m_fNumber1 = f;
	m_fNumber2 = 0.0f;
}


void Ccalculator1Dlg::OnButtonTan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));	
	if (cos(m_fNumber1 * PI / 180) <= 1e-5 && cos(m_fNumber1 * PI / 180) >= -1e-5)
	{
		m_str = (CString)"MATH ERROR";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		double f = tan(m_fNumber1 * PI / 180);
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
	}
	
	m_number = 0;

	UpdateData(FALSE);

}


void Ccalculator1Dlg::OnButton00()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_number > 0)
	{
		m_str = m_str + (CString)"00";
	}
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonPI()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	str_to_double(PI);
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonN()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	if (m_symbol == 1)
	{
		//�����������ʵ���Ǹ�����
		if (m_fNumber1 - int(m_fNumber1) >= 1e-5)
		{
			m_str = (CString)"MATH ERROR";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else if (m_fNumber1 >= 16)
		{
			m_str = (CString)"OUT OF RANGE";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			int j = 1;
			for (int i = 1; i <= m_fNumber1; i++)
			{
				j *= i;
			}
			str_to_double(j);
			m_fNumber1 = j;
			m_fNumber2 = 0.0f;
		}
	}
	else
	{
		//�����������ʵ���Ǹ�����
		if ((-m_fNumber1 - int(m_fNumber1)) >= 1e-5)
		{
			m_str = (CString)"MATH ERROR";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else if (m_fNumber1 <= -16)
		{
			m_str = (CString)"OUT OF RANGE";
			m_number = 0;
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			int j = 0;
			for (int i = 1; i <= m_fNumber1; i++)
			{
				j *= i;
			}
			str_to_double(j);
			m_fNumber1 = j;
			m_fNumber2 = 0.0f;
		}
	}
	
		UpdateData(FALSE);

		m_number = 0;
}


void Ccalculator1Dlg::OnButtonX_Y()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SaveValue1();
	m_number = 0;
	m_iSign = 8;
}


void Ccalculator1Dlg::OnButtonLog()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	if (m_fNumber1 <= 0)
	{
		m_str = (CString)"MATH ERROR";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		double f = log10(m_fNumber1 );
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
	}

	m_number = 0;

	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonLn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_fNumber1 = _wtof(m_str.GetBuffer(0));
	if (m_fNumber1 <= 0)
	{
		m_str = (CString)"MATH ERROR";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		double f = log(m_fNumber1);
		str_to_double(f);
		m_fNumber1 = f;
		m_fNumber2 = 0.0f;
	}

	m_number = 0;

	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnButtonNot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num == 10)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		int y = m_str.GetLength();
		SaveValue1();
		int x;
		int z = 0;
		x = (int)m_fNumber1;
		for (int i = 0, j = 1; i < y; i++)
		{
			if (x % 10 == 0)
			{
				z += j;
			}
			j *= 10;
			x /= 10;
		}
		str_to_double(z);
		m_fNumber1 = z;
		m_fNumber2 = 0.0f;
	}
	m_number = 0;
	UpdateData(FALSE);


}


void Ccalculator1Dlg::OnButtonAnd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_num == 10)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		m_iSign = 10;
		m_2 = m_str.GetLength();
		SaveValue1();
	}

	m_number = 0;
}


void Ccalculator1Dlg::OnRadioChange_2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num == 2)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		double f;
		f = _wtof(m_str.GetBuffer(0));
		//�����������ʵ���Ǹ�����
		if (f - int(f) >= 1e-5 || (-f - int(f)) >= 1e-5)
		{
			m_str = (CString)"PLEASE INPUT A INTEGER";
			m_time = 0;
			m_symbol = 1;
		}
		else
		{
			int n = (int)f;
			m_str = "";
			for (int i = 16; i >= 0; i--)
			{
				if (n & (1 << i))
					m_str += "1";
				else
					m_str += "0";
				if (-1 == m_str.Find('1'))
				{
					m_str = "";
				}
			}
			m_num = 2;
		}
	}

	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnFineClose()
{
	// TODO: �ڴ���������������
	CDialogEx::OnCancel();
}


void Ccalculator1Dlg::OnRadioChange_10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num == 10)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		int number = 0;
		int w = 1;
		for (int i = m_str.GetLength() - 1; i >= 0; i--)
		{
			if (m_str[i] == '1')
			{
				number += w;
			}
			w *= 2;
		}
		m_str = "";
		str_to_double(number);
		m_num = 10;
	}
	m_number = 0;
	UpdateData(FALSE);
}


void Ccalculator1Dlg::OnHelpAbout()
{
	// TODO: �ڴ���������������
	CAboutDlg dlg;
	dlg.DoModal();
}


void Ccalculator1Dlg::OnButtonOr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_num == 10)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		m_iSign = 11;
		m_2 = m_str.GetLength();
		SaveValue1();
	}

	m_number = 0;
}


void Ccalculator1Dlg::OnButtonXol()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_num == 10)
	{
		m_str = (CString)"WRONG OPERATION";
		m_time = 0;
		m_symbol = 1;
	}
	else
	{
		m_iSign = 12;
		m_2 = m_str.GetLength();
		SaveValue1();
	}

	m_number = 0;
}
