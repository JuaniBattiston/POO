#ifndef LINEA_H
#define LINEA_H

class Linea
{
public:
    Linea(int x_inicial = 0, int y_inicial = 0, int x_final = 1, int y_final = 1);
    void set_x_inicial(const int x_inicial);
    void set_y_inicial(const int y_inicial);
    void set_x_final(const int x_final);
    void set_y_final(const int y_final);
    int get_x_inicial() const;
    int get_y_inicial() const;
    int get_x_final() const;
    int get_y_final() const;

private:
    int x_inicial;
    int x_final;
    int y_inicial;
    int y_final;
};

#endif // LINEA_H
