#include "PassWindow.hpp"

//ctor & dtor

PassWindow::PassWindow(QWidget* parent)
	: QMainWindow(parent)
{
	//	Instantiate objects
	this->vlayout = new QVBoxLayout(this);
	this->entriesLayout = new QVBoxLayout(this);
	this->mainWidget = new QWidget(this);
	this->titleLabel = new QLabel(this);
	this->entriesBox = new QGroupBox(this);
	this->emailLabel = new QLabel(this);
	this->emailEntry = new PLineEdit(this);
	this->passwordLayout = new QHBoxLayout(this);
	this->passwordLabel = new QLabel(this);
	this->forgotButton = new QPushButton(this);
	this->passwordEntry = new PLineEdit(this);
	this->loginButton = new QPushButton(this);
	this->errorLabel = new QLabel(this);


	//	Window
	resize(750, 600);
	setMinimumSize(QSize(450, 500));
	setWindowIcon(QIcon("window_icon.ico"));
	setWindowTitle("PaMa");
	setStyleSheet("QMainWindow{background: #FCFCFA;} color: #0A0905;");
	

	//	Body
	// Title
	this->titleLabel->setText(tr("Sign in to PaMa"));
	this->vlayout->addWidget(this->titleLabel);
	// Entries
	//email
	this->emailLabel->setText(tr("Email adress"));
	this->entriesLayout->addWidget(this->emailLabel);
	this->entriesLayout->addSpacing(10);
	this->entriesLayout->addWidget(this->emailEntry);
	this->entriesLayout->addSpacing(20);
	//password
	this->passwordLabel->setText(tr("Password"));
	this->passwordLayout->addWidget(this->passwordLabel);
	this->forgotButton->setText(tr("Forgot password?"));
	this->passwordLayout->addWidget(this->forgotButton);
	this->entriesLayout->addLayout(this->passwordLayout);
	this->entriesLayout->addSpacing(10);
	this->entriesLayout->addWidget(this->passwordEntry);
	this->entriesLayout->addSpacing(5);
	this->entriesLayout->addWidget(this->errorLabel);
	this->entriesLayout->addSpacing(20);
	//login
	this->loginButton->setText(tr("&Sign in"));
	this->entriesLayout->addWidget(this->loginButton);

	this->entriesBox->setLayout(this->entriesLayout);
	this->vlayout->addWidget(this->entriesBox);

	//	Set Central Widget
	this->mainWidget->setLayout(this->vlayout);
	setCentralWidget(mainWidget);


	//	Style
	//title
	this->titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
	this->titleLabel->setFont(NS40_N().get());
	//vlayout
	this->vlayout->setAlignment(Qt::AlignmentFlag::AlignCenter);
	this->vlayout->setSpacing(40);
	//entriesBox
	this->entriesBox->setStyleSheet("QGroupBox {border: 1px solid #7E7D79; border-radius: 10px;}");
	this->entriesBox->setFixedWidth(350);
	//entriesLayout
	this->entriesLayout->setSpacing(0);
	this->entriesLayout->setContentsMargins(QMargins(25, 30, 25, 20));
	//email
	this->emailLabel->setFixedSize(QSize(300, 20));
	this->emailLabel->setFont(NS18_N().get());
	this->emailEntry->setFixedSize(QSize(300, 50));
	this->emailEntry->setFont(NS15_N().get());
	this->emailEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #7E7D79; }");
	//passwordLayout
	this->passwordLayout->setSpacing(0);
	//password
	this->passwordLabel->setFixedSize(QSize(160, 20));
	this->passwordLabel->setFont(NS18_N().get());
	this->forgotButton->setCursor(Qt::CursorShape::PointingHandCursor);
	this->forgotButton->setFixedSize(QSize(140, 30));
	this->forgotButton->setFont(NS15_N().get());
	this->forgotButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	this->forgotButton->setStyleSheet("QPushButton{ outline: 0; text-align:left; padding: 5px; border: 0px; color: #486ED9; border-radius: 5px; } QPushButton:hover{ text-decoration: underline; } QPushButton:pressed{ color: #4862A8; }");
	this->passwordEntry->setFixedSize(QSize(300, 50));
	this->passwordEntry->setFont(NS15_N().get());
	this->passwordEntry->setEchoMode(QLineEdit::EchoMode::Password);
	this->passwordEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #7E7D79; }");
	//login
	this->loginButton->setFixedSize(QSize(300, 36));
	this->loginButton->setFont(NS20_N().get());
	this->loginButton->setCursor(Qt::CursorShape::PointingHandCursor);
	this->loginButton->setStyleSheet("QPushButton{ outline: 0; border-radius: 5px; border: 0px; background: #486ED9; color: white;} QPushButton:hover{background: #4862A8;}");
	//error
	this->errorLabel->setFont(NS15_N().get());
	this->errorLabel->setStyleSheet("QLabel{ color: #EB0000; }");


	//	Back
	QObject::connect(this->emailEntry, &PLineEdit::focused, this, &PassWindow::clear_error);
	QObject::connect(this->forgotButton, &QPushButton::pressed, this, &PassWindow::password_forgot);
	QObject::connect(this->passwordEntry, &QLineEdit::returnPressed, this, &PassWindow::check_password);
	QObject::connect(this->passwordEntry, &PLineEdit::focused, this, &PassWindow::clear_error);
	QObject::connect(this->loginButton, &QPushButton::pressed, this, &PassWindow::check_password);
}

PassWindow::~PassWindow()
{
}

//private methods

void PassWindow::raise_error(const QString message)
{
	this->errorLabel->setText(message);
	this->emailEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #EB0000; }");
	this->passwordEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #EB0000; }");
	this->emailEntry->clearFocus();
	this->passwordEntry->clearFocus();
	this->is_error_raised = true;
}

//private slots

void PassWindow::clear_error()
{
	if (this->is_error_raised)
	{
		this->errorLabel->clear();
		this->emailEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #7E7D79; }");
		this->passwordEntry->setStyleSheet("QLineEdit{ " + this->entryStyle + "border: 1px solid #7E7D79; }");
		this->is_error_raised = false;
	}
}

void PassWindow::password_forgot()
{
	qDebug() << "password forgot";
}

void PassWindow::check_password()
{
	//pre check
	this->loginButton->setDisabled(true);
	const QString email = this->emailEntry->text();
	const QString password = this->passwordEntry->text();

	//check
	if (email == "elie" && password == "elie")
	{
		qDebug() << true;
		emit password_validated(password);
		close();
	}
	else
	{
		this->raise_error("Email or password wrong.");
		--this->remaining_tests;
		if (this->remaining_tests <= 0)
		{
			close();
		}
	}

	//post chech
	this->loginButton->setEnabled(true);
}