#include <iostream>
#include <string>
using namespace std;

// Interfaz de Notificacion
class INotificacion {
public:
    virtual void enviar(const string& mensaje) = 0;
    virtual ~INotificacion() {}
};

// Notificacion por Email
class NotificacionEmail : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[Email] Enviando mensaje: " << mensaje << endl;
    }
};

// Notificacion Push
class NotificacionPush : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[Push] Enviando mensaje: " << mensaje << endl;
    }
};

// Notificacion por Mensaje de Texto (SMS)
class NotificacionSMS : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[SMS] Enviando mensaje: " << mensaje << endl;
    }
};

// Fabrica de Notificaciones
class NotificacionFactory {
public:
    static INotificacion* crear(const string& tipo) {
        if (tipo == "email") return new NotificacionEmail();
        if (tipo == "push")  return new NotificacionPush();
        if (tipo == "sms")   return new NotificacionSMS();
        return nullptr;
    }
};

// Funcion principal
int main() {
    string tipo;
    cout << "Que tipo de notificacion desea enviar? (email, push, sms): ";
    cin >> tipo;

    INotificacion* notif = NotificacionFactory::crear(tipo);
    if (notif) {
        notif->enviar("Hola, esta es una notificacion importante.");
        delete notif;
    } else {
        cout << "Tipo de notificacion no valido.\n";
    }

    return 0;
}
