#include <iostream>
#include <string>
#include <vector>

class Instrumento {
public:
    virtual void sonar() const = 0;

    virtual void verlo() const {
        std::cout << "Marca: Yamaha" << std::endl;
    }

    virtual ~Instrumento() {}
};

class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    inline Guitarra(int _cuerdas = 6) : cuerdas(_cuerdas) {}

    inline void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
    }

    inline int getCuerdas() const { return cuerdas; }

    inline void setCuerdas(int _cuerdas) { cuerdas = _cuerdas; }
};

class Bateria : public Instrumento {
private:
    int tambores;

public:
    inline Bateria(int _tambores = 5) : tambores(_tambores) {}

    inline void sonar() const override {
        std::cout << "Batería suena..." << std::endl;
    }

    inline int getTambores() const { return tambores; }

    inline void setTambores(int _tambores) { tambores = _tambores; }
};

class Electrico {
public:
    inline Electrico() {}

    inline ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }

    inline int getVoltaje() const { return 220; }
};

class Teclado : public Instrumento, public Electrico {
private:
    int teclas;

public:
    inline Teclado(int _teclas = 61) : teclas(_teclas) {}

    inline void sonar() const override {
        std::cout << "Teclado suena..." << std::endl;
    }

    inline int getTeclas() const { return teclas; }

    inline void setTeclas(int _teclas) { teclas = _teclas; }
};

int main() {
    std::vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());

    for (const auto& inst : instrumentos) {
        inst->verlo();
        inst->sonar();
        if (auto* guitarra = dynamic_cast<Guitarra*>(inst)) {
            std::cout << "Cuerdas: " << guitarra->getCuerdas() << std::endl;
        } else if (auto* bateria = dynamic_cast<Bateria*>(inst)) {
            std::cout << "Tambores: " << bateria->getTambores() << std::endl;
        } else if (auto* teclado = dynamic_cast<Teclado*>(inst)) {
            std::cout << "Teclas: " << teclado->getTeclas() << std::endl;
            std::cout << "Voltaje: " << teclado->getVoltaje() << " volts" << std::endl;
        }
    }

    for (const auto& inst : instrumentos) {
        delete inst;
    }

    return 0;
}
