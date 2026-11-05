#include "Utilidades.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;

bool g_eof = false;

string recortar(const string& s) {
    size_t a = 0, b = s.size();
    while (a < b && isspace((unsigned char)s[a])) a++;
    while (b > a && isspace((unsigned char)s[b - 1])) b--;
    return s.substr(a, b - a);
}

vector<string> dividir(const string& s, char sep) {
    vector<string> r;
    size_t ini = 0;
    while (true) {
        size_t p = s.find(sep, ini);
        if (p == string::npos) { r.push_back(s.substr(ini)); break; }
        r.push_back(s.substr(ini, p - ini));
        ini = p + 1;
    }
    return r;
}

string aMayusculas(const string& s) {
    string r = s;
    for (size_t i = 0; i < r.size(); i++) r[i] = (char)toupper((unsigned char)r[i]);
    return r;
}

bool contieneTexto(const string& pajar, const string& aguja) {
    string a = pajar, b = aguja;
    for (size_t i = 0; i < a.size(); i++) a[i] = (char)tolower((unsigned char)a[i]);
    for (size_t i = 0; i < b.size(); i++) b[i] = (char)tolower((unsigned char)b[i]);
    return a.find(b) != string::npos;
}

string minutosAHora(int m) {
    m = ((m % MINUTOS_DIA) + MINUTOS_DIA) % MINUTOS_DIA;
    char buf[32];
    snprintf(buf, sizeof(buf), "%02d:%02d", m / 60, m % 60);
    return string(buf);
}

bool parsearHora(const string& s, int& minutos) {
    size_t p = s.find(':');
    if (p == string::npos || p == 0 || p > 2 || s.size() - p - 1 != 2) return false;
    string h = s.substr(0, p), m = s.substr(p + 1);
    for (size_t i = 0; i < h.size(); i++) if (!isdigit((unsigned char)h[i])) return false;
    for (size_t i = 0; i < m.size(); i++) if (!isdigit((unsigned char)m[i])) return false;
    int hh = atoi(h.c_str()), mm = atoi(m.c_str());
    if (hh > 23 || mm > 59) return false;
    minutos = hh * 60 + mm;
    return true;
}

bool parsearEntero(const string& s, int& valor) {
    if (s.empty() || s.size() > 6) return false;
    for (size_t i = 0; i < s.size(); i++) if (!isdigit((unsigned char)s[i])) return false;
    valor = atoi(s.c_str());
    return true;
}

int minutosActuales() {
    time_t t = time(nullptr);
    tm* l = localtime(&t);
    if (l == nullptr) return 0;
    return l->tm_hour * 60 + l->tm_min;
}

string fechaActual() {
    time_t t = time(nullptr);
    tm* l = localtime(&t);
    if (l == nullptr) return "0000-00-00";
    char buf[16];
    strftime(buf, sizeof(buf), "%Y-%m-%d", l);
    return string(buf);
}

bool dentroDePlazo(int ahora, int objetivo) {
    int d = ahora - objetivo;
    return d >= -TOLERANCIA_MIN && d <= TOLERANCIA_MIN;
}

static bool esLetra(unsigned char c) { return isalpha(c) || c >= 128; }

bool esCedulaValida(const string& s) {
    if (s.size() != 10) return false;
    for (size_t i = 0; i < s.size(); i++) if (!isdigit((unsigned char)s[i])) return false;

    int provincia = (s[0] - '0') * 10 + (s[1] - '0');
    if (!((provincia >= 1 && provincia <= 24) || provincia == 30)) return false;
    if (s[2] - '0' >= 6) return false;

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int v = (s[i] - '0') * (i % 2 == 0 ? 2 : 1);
        if (v > 9) v -= 9;
        suma += v;
    }
    int verificador = (10 - suma % 10) % 10;
    return verificador == s[9] - '0';
}

bool esIdValido(const string& s) {
    if (s.empty() || s.size() > 10) return false;
    for (size_t i = 0; i < s.size(); i++) if (!isalnum((unsigned char)s[i])) return false;
    return true;
}

bool esNombreValido(const string& s) {
    if (s.empty() || s.size() > 40) return false;
    bool hayLetra = false;
    for (size_t i = 0; i < s.size(); i++) {
        unsigned char c = (unsigned char)s[i];
        if (esLetra(c)) hayLetra = true;
        else if (c != ' ' && c != '-' && c != '\'') return false;
    }
    return hayLetra;
}

bool esTextoValido(const string& s) {
    if (s.empty() || s.size() > 60) return false;
    for (size_t i = 0; i < s.size(); i++) {
        unsigned char c = (unsigned char)s[i];
        if (c < 32 || c == 127 || c == '|') return false;
    }
    return true;
}

bool esFechaValida(const string& s) {
    if (s.size() != 10 || s[4] != '-' || s[7] != '-') return false;
    for (size_t i = 0; i < s.size(); i++)
        if (i != 4 && i != 7 && !isdigit((unsigned char)s[i])) return false;
    int anio = atoi(s.substr(0, 4).c_str());
    int mes  = atoi(s.substr(5, 2).c_str());
    int dia  = atoi(s.substr(8, 2).c_str());
    if (anio < 2000 || anio > 2100 || mes < 1 || mes > 12 || dia < 1) return false;
    static const int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maximo = dias[mes - 1];
    if (mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)) maximo = 29;
    return dia <= maximo;
}

bool esFranjaValida(int ini, int fin, string& motivo) {
    if (ini < HORA_APERTURA) {
        motivo = "no se pueden crear franjas antes de las " + minutosAHora(HORA_APERTURA) + ".";
        return false;
    }
    if (ini >= HORA_CIERRE || fin > HORA_CIERRE) {
        motivo = "no se pueden crear franjas que terminen despues de las " + minutosAHora(HORA_CIERRE) +
                 " (la ultima franja es " + minutosAHora(HORA_CIERRE - DURACION_FRANJA) + " - " +
                 minutosAHora(HORA_CIERRE) + ").";
        return false;
    }
    if (fin - ini != DURACION_FRANJA) {
        motivo = "toda franja debe durar exactamente 2 horas (ni mas ni menos).";
        return false;
    }
    return true;
}

string leer(const string& mensaje) {
    cout << mensaje;
    string linea;
    if (!getline(cin, linea)) { g_eof = true; return ""; }
    return recortar(linea);
}

bool leerCampo(const string& mensaje, bool (*valida)(const string&),
               const string& error, string& destino, bool opcional) {
    while (true) {
        string s = leer(mensaje);
        if (g_eof || s.empty()) return false;
        if (valida(s)) { destino = s; return true; }
        cout << "  " << error << (opcional ? " (ENTER vacio = conservar el actual)"
                                            : " (ENTER vacio = cancelar)") << endl;
    }
}

bool leerHora(const string& mensaje, int& minutos) {
    while (true) {
        string s = leer(mensaje);
        if (g_eof || s.empty()) return false;
        if (parsearHora(s, minutos)) return true;
        cout << "  Hora invalida. Use HH:MM entre 00:00 y 23:59. (ENTER vacio = cancelar)" << endl;
    }
}

bool confirmar(const string& mensaje) {
    while (true) {
        string s = aMayusculas(leer(mensaje + " (s/n): "));
        if (g_eof) return false;
        if (s == "S" || s == "SI") return true;
        if (s == "N" || s == "NO" || s.empty()) return false;
        cout << "  Responda s o n." << endl;
    }
}
