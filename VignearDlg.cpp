// VignearDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Vignear.h"
#include "VignearDlg.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVignearDlg dialog
#define M 1000

class sq
{
public:
	int a[M];
	int length;
	

    int f[26];
	void freq();

    float Ic(int n);
	sq()
	{
		int i;
		for(i=0;i<M;i++) 
			a[i]=0;
		length=0;
		for(i=0;i<26;i++) 
			f[i]=0;
	}
};

void sq::freq()
{
	int i,j;
	for(i=0;i<26;i++)
		f[i]=0;
	for(i=0;i<length;i++)
	{
		for(j=0;j<26;j++)
		{
			if (a[i]==j)
				f[j]++;
		}
	}
	
}

float sq::Ic(int n)
{
	int i;
	float s=0;
	for(i=0;i<26;i++)
	{
		s+=float(f[i]*(f[i]-1));
	}
	s=s/n/(n-1);
	return s;

}

int ctext1[M],cou[M];
int ctext2[M];
int key1[M];
int key2[M];
int lth1=0;
int lth2=0;
int keylength1;
int keylength2;
sq squence;



CVignearDlg::CVignearDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVignearDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVignearDlg)
	m_edit1 = _T("");
	m_edit2 = _T("");
	m_edit3 = _T("");
	m_edit4 = _T("");
	m_edit5 = _T("");
	m_edit6 = _T("");
	m_edit7 = _T("");
	m_edit8 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVignearDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVignearDlg)
	DDX_Control(pDX, IDC_EDIT8, c_edit8);
	DDX_Control(pDX, IDC_EDIT7, c_edit7);
	DDX_Control(pDX, IDC_EDIT6, c_edit6);
	DDX_Control(pDX, IDC_EDIT5, c_edit5);
	DDX_Control(pDX, IDC_EDIT4, c_edit4);
	DDX_Control(pDX, IDC_EDIT3, c_edit3);
	DDX_Control(pDX, IDC_EDIT2, c_edit2);
	DDX_Control(pDX, IDC_EDIT1, c_edit1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	DDX_Text(pDX, IDC_EDIT7, m_edit7);
	DDX_Text(pDX, IDC_EDIT8, m_edit8);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVignearDlg, CDialog)
	//{{AFX_MSG_MAP(CVignearDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVignearDlg message handlers

BOOL CVignearDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVignearDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVignearDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVignearDlg::OnButton1()  //输入密文
{
	int i=0;
	int t;
	UpdateData(TRUE);
	c_edit1.GetWindowText(m_edit1);
	if(!m_edit1)
	{
        MessageBox("未知密文!请输入.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}
	while (i<m_edit1.GetLength()) 
	{ 
		t=m_edit1.GetAt(i)-'A';
		if ((t<0)||(t>25)) 
		{
			MessageBox("输入有错，每位必须是26个大写英文字母'A' 到 'Z'!","错误!",MB_ICONEXCLAMATION);
			c_edit1.SetFocus();
	        UpdateData(FALSE);
			return;
		}
		else i++;
	}
	i=0;
	while (i<m_edit1.GetLength())
	{
		t=m_edit1.GetAt(i)-'A';
		ctext1[i]=t;
		i++;
		
	}
	lth1=m_edit1.GetLength();
}


int LCM(int m,int n)//辗转相除
{
	int  a=m,r,b=n;
	while(n)
	{
		r=n;
		n=m%n;
		m=r;
	}
	return m;
}

	


void CVignearDlg::OnButton2()     //密钥长度计算
{
	int i,j,m=2;
	int n;
	float I[M];
	float averI=0;
	double min=1;
	UpdateData(TRUE);   
	m_edit2.Empty();
	UpdateData(FALSE);
	
	if(!lth1)
	{
        MessageBox("未输入密文!请按第一步按钮输入确定.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}

	//Kasiski 测试法
	int count = 0,k = 0;
	while(count <= 1)
	{
		for(i=3;i<lth1;i++)
		{
			if(ctext1[k] == ctext1[i]  && ctext1[k+1] == ctext1[i+1] && ctext1[k+2] == ctext1[i+2])
			{
				cou[count] = i - k ;
				count++;
			}
		}
		k++;
	}
	for(i=0;i<count-1;i++)
		cou[i+1]=LCM(cou[i],cou[i+1]);
	count = cou[i];



//重合指数法
	while(1)
	{

		for(i=0;i<=m-1;i++)
		{
			n=(int)lth1/m;
			squence.length=n;
			for(j=0;j<n;j++)
			{
				squence.a[j]=ctext1[i+j*m];
			}
			squence.freq();
            I[i]=squence.Ic(n);
		}
		averI=0;
        for(i=0;i<=m-1;i++)
		{
			averI+=I[i];
		}
		averI=averI/m;
		if (fabs(averI-0.065)<=0.005) 
			break;
		
		else m++;
	}
	if(count % m == 0)
	{
		keylength1=m;
	}
    UpdateData(TRUE);
	m_edit2=m+'0';
	UpdateData(FALSE);
}



void CVignearDlg::OnButton3()     //推出密钥函数
{
	double p[26]={0.082,0.015,0.028,0.043,0.127,0.022,0.020,0.061,0.070,0.002,0.008,0.040,0.024,
		          0.067,0.075,0.019,0.001,0.060,0.063,0.091,0.028,0.010,0.023,0.001,0.020,0.001};
	int i,j,k,g;
	int n;
	double Mg=0,min=1;

	UpdateData(TRUE);   
	m_edit3.Empty();
	UpdateData(FALSE);

	if(!keylength1)
	{
        MessageBox("未知密钥长度!请按第二步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		
		return;
	}
	for(i=0;i<keylength1;i++)
	{
			n=(int)lth1/keylength1;
			squence.length=n;
			for(j=0;j<n;j++)
			{
				squence.a[j]=ctext1[i+j*keylength1];
			}
			squence.freq();
			min=1;

			for(g=0;g<26;g++)
			{   
				Mg=0;
				for(k=0;k<26;k++)
				{
					Mg+=(p[k]*squence.f[(k+g)%26])/n;
				}
				if(fabs(Mg-0.065)<min)	
				{
					key1[i]=g;
					min=fabs(Mg-0.065);
				}
			}

	}
	UpdateData(TRUE);
	for(i=0;i<keylength1;i++)
	{
		m_edit3+=key1[i]+'A';
	}
	UpdateData(FALSE);

}

void CVignearDlg::OnButton4()     //算出明文
{
	int i,j;
	int n;
	int rest;
	int s=0;

	UpdateData(TRUE);   
	m_edit4.Empty();
	UpdateData(FALSE);

	if(!lth1)
	{
        MessageBox("未知密文!请按第一步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}

	if(!keylength1)
	{
        MessageBox("未知密钥长度!请按第二步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		
		return;
	}

    for(j=0;j<keylength1;j++) 
		s+=key1[j];
	if(!s)
	{
        MessageBox("未知密钥!请按第三步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}

	n=(int)lth1/keylength1;
	rest=lth1%keylength1;
    
	UpdateData(TRUE);
	for(i=0;i<n;i++)
	{
		for(j=0;j<keylength1;j++)
		{
			m_edit4+=(ctext1[i*keylength1+j]+26-key1[j])%26+'a';
		}
	}
	for(j=0;j<rest;j++)
	{
		m_edit4+=(ctext1[i*keylength1+j]+26-key1[j])%26+'a';
	}
	UpdateData(FALSE);

}


void CVignearDlg::OnButton5()  //输入明文
{
	int i=0;
	int t;
	UpdateData(TRUE);
	c_edit5.GetWindowText(m_edit5);
	if(!m_edit5)
	{
        MessageBox("未知密文!请输入.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}
	while (i<m_edit5.GetLength()) 
	{ 
		t=m_edit5.GetAt(i)-'a';
		if ((t<0)||(t>25)) 
		{
			MessageBox("输入有错，每位必须是26个大写英文字母'A' 到 'Z'!","错误!",MB_ICONEXCLAMATION);
			c_edit5.SetFocus();
	        UpdateData(FALSE);
			return;
		}
		else i++;
	}
	i=0;
	while (i<m_edit5.GetLength())
	{
		t=m_edit5.GetAt(i)-'a';
		ctext2[i]=t;
		i++;
	}
	lth2=m_edit5.GetLength();
	
}


void CVignearDlg::OnButton6()  //输入密钥
{
	c_edit6.GetWindowText(m_edit6);
	if(!m_edit6)
	{
        MessageBox("未知密钥!请输入.",
			       "提示!",MB_ICONINFORMATION);
		return;
	}
	keylength2=m_edit6.GetLength();
	int i = 0,t;
	while (i<m_edit6.GetLength())
	{
		t=m_edit6.GetAt(i)-'A';
		key2[i]=t;
		i++;
	}
	return;
	
}

void CVignearDlg::OnButton7()  //输出密文
{
    int i,j;
	int n;
	int rest;
	int s=0;

	UpdateData(TRUE);   
	m_edit7.Empty();
	UpdateData(FALSE);

	if(!lth2)
	{
        MessageBox("未知明文!请按第一步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		
		return;
	}

	if(!keylength2)
	{
        MessageBox("未知密钥!请按第二步按钮生成.",
			       "提示!",MB_ICONINFORMATION);
		
		return;
	}

	n=(int)lth2/keylength2;
	rest=lth2%keylength2;
    
	UpdateData(TRUE);
	for(i=0;i<n;i++)
	{
		for(j=0;j<keylength2;j++)
		{
			m_edit7+=(ctext2[i*keylength2+j]+key2[j])%26+'A';
		}
	}
	for(j=0;j<rest;j++)
	{
		m_edit7+=(ctext2[i*keylength2+j]+key2[j])%26+'A';
	}
	UpdateData(FALSE);
	
}


void CVignearDlg::OnButton8() 
{
	double p[26]={0.082,0.015,0.028,0.043,0.127,0.022,0.020,0.061,0.070,0.002,0.008,0.040,0.024,
		          0.067,0.075,0.019,0.001,0.060,0.063,0.091,0.028,0.010,0.023,0.001,0.020,0.001};
	int i,j,k,g;
	int n;
	double Mg=0,min=1;

	UpdateData(TRUE);   
	m_edit8.Empty();
	UpdateData(FALSE);

	UpdateData(TRUE);
	for(i=0;i<keylength1;i++)
	{
			n=(int)lth1/keylength1;
			squence.length=n;
			for(j=0;j<n;j++)
			{
				squence.a[j]=ctext1[i+j*keylength1];
			}
			squence.freq();
			min=1;

			for(g=0;g<26;g++)
			{   
				Mg=0;
				for(k=0;k<26;k++)
				{
					Mg+=(p[k]*squence.f[(k+g)%26])/n;
				}
				if(fabs(Mg-0.065)<min)	
				{
					key1[i]=g;
					min=fabs(Mg-0.065);
				}
   
				char buf[20];
				sprintf(buf, "%.7lf\n", Mg);
				puts(buf);
				m_edit8+=buf;
				m_edit8+="  ";
			}			

			m_edit8+="\r\n";
			m_edit8+="所以，第";
			m_edit8+=i+'1';
			m_edit8+="个密钥是：";
			m_edit8+=key1[i]+'A';
			m_edit8+="\r\n";
	}
	UpdateData(FALSE);

	
}
