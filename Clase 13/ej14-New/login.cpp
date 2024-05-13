#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , managerjson (new QNetworkAccessManager(this))
    , managerimgs (new QNetworkAccessManager(this))
    , login_atts(0)
{

    db = adminDB.getDB();
    if (adminDB.conectar( "C:\\Users\\juani\\OneDrive\\Escritorio\\POO\\Clase 12\\db.sqlite" ) )
        qDebug() << "Conexion exitosa";

    const int BLOCK_DURATION = 5 * 60 * 1000; // 5 minutes in milliseconds
    bool is_blocked = false;
    timer.setSingleShot(true);
    formulario = new Formulario();

    QLabel *lUser = new QLabel("Usuario:");
    QLabel *lPassword = new QLabel("Clave:");
    lWeather = new QLabel("Weather Info");
    cbHideTemp = new QCheckBox("Hide Temp");
    backgroundLabel = new QLabel;

    leUser = new QLineEdit;
    lePassword = new QLineEdit;
    lePassword->setEchoMode(QLineEdit::Password);

    pbLogin = new QPushButton("Ingresar");

    leImageUrl = new QLineEdit;
    pbSetBackground = new QPushButton("Set Background");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUser, 0, 0);
    layout->addWidget(lPassword, 1, 0);
    layout->addWidget(leUser, 0, 1);
    layout->addWidget(lePassword, 1, 1);
    layout->addWidget(pbLogin, 2, 1);
    layout->addWidget(lWeather, 3, 1);
    layout->addWidget(cbHideTemp, 4, 1);
    layout->addWidget(leImageUrl, 5, 0, 1, 2);
    layout->addWidget(pbSetBackground, 6, 0, 1, 2);

    setLayout(layout);

    connect(pbLogin, SIGNAL(pressed()), this, SLOT(slot_validate_user()));
    connect(lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validate_user()));

    connect(managerjson, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_handle_temp_resp(QNetworkReply*)));
    QString url_string = "https://api.weatherapi.com/v1/current.json?key=e59137c754614dfebf9224202240304&q=-31.4135%20-64.18105";
    managerjson->get(QNetworkRequest(QUrl(url_string)));
    connect(cbHideTemp, SIGNAL(stateChanged(int)), this, SLOT(slot_toggleTempLabelVisibility(int)));

    QString url_string_2 = "https://img.freepik.com/foto-gratis/papel-pintado-gatito-lindo-fantasia_1409-6188.jpg";
    managerimgs->get(QNetworkRequest(QUrl(url_string_2)));
    connect(managerimgs, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_downloadFinished(QNetworkReply*)));

    connect(pbSetBackground, SIGNAL(pressed()), this, SLOT(slot_set_bg_img()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validate_user()
{
    bool valid_user = false;
    QStringList result = adminDB.validarUsuario(QString("usuarios"),leUser->text(), lePassword->text());
    if (result.size() > 0) {
        valid_user = true;
    }
    if (valid_user) {
        qDebug() << "Usuario válido";
        formulario->show();
        this->hide();
        login_atts = 0;

    } else {
        qDebug() << "Usuario inválido";
        login_atts++;

        if (login_atts >= 3) {
            qDebug() << "3 intentos fallidos";


            blockUser();

            login_atts = 0;
        }
    }
}

void Login::blockUser()
{

    leUser->setEnabled(false);
    lePassword->setEnabled(false);
    pbLogin->setEnabled(false);

    timer.start(BLOCK_DURATION);

    connect(&timer, &QTimer::timeout, this, &Login::unblockUser);
}

void Login::unblockUser()
{

    leUser->setEnabled(true);
    lePassword->setEnabled(true);
    pbLogin->setEnabled(true);

    disconnect(&timer, &QTimer::timeout, this, &Login::unblockUser);
}

void Login::slot_toggleTempLabelVisibility(int state)
{
    if (state == Qt::Checked)
    {
        lWeather->hide();
    }
    else
    {
        lWeather->show();
    }
}

void Login::slot_handle_temp_resp(QNetworkReply * reply) {
    QByteArray response = reply->readAll();
    QJsonParseError jsonError;
    QJsonDocument json_response = QJsonDocument::fromJson(response, &jsonError);

    if(jsonError.error != QJsonParseError::NoError){
        qDebug() << "Error";
        return;
    }

    QJsonObject jsonObject = json_response.object();
    if (jsonObject.contains("current")) {
        QJsonObject currentObject = jsonObject["current"].toObject();
        if (currentObject.contains("temp_c")) {
            QJsonValue tempValue = currentObject["temp_c"];
            if (tempValue.isDouble()) {
                double temperature = tempValue.toDouble();
                QString responseString = QString::number(temperature);
                QString temp = "Temperatura: ";
                lWeather->setText(temp + responseString);
            } else {
                qDebug() << "Temperature value is not a double.";
            }
        } else {
            qDebug() << "No 'temp_c' field in 'current' object.";
        }
    } else {
        qDebug() << "No 'current' object in JSON response.";
    }
}

void Login::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if (!image.isNull()) {
        p.drawImage(0, 0, image.scaled(this->width(), this->height()));
    }
}

void Login::slot_downloadFinished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    if (!image.isNull()) {
        this->repaint();
    }

}

void Login::slot_set_bg_img()
{
    QString url_string = leImageUrl->text();
    managerimgs->get(QNetworkRequest(QUrl(url_string)));
}
