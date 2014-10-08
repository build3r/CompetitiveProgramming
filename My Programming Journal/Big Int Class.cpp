class bigint {
    static const int maxlength = 2000;
    int oper, length, a[maxlength];
public:
    bigint(int = 0);
    bigint(char *s);
    ~bigint();
    void check();
    void operator=(bigint m);
    void operator=(int m);
    void operator=(char *s);
    bool operator<(bigint m);
    bool operator<=(bigint m);
    bool operator>(bigint m);
    bool operator>=(bigint m);
    bool operator==(bigint m);
    bool operator!=(bigint m);
    bigint operator-();
    bigint operator+(bigint m);
    void operator+=(bigint m);
    bigint operator-(bigint m);
    void operator-=(bigint m);
    bigint operator*(bigint m);
    bigint operator*(int m);
    void operator*=(bigint m);
    void operator*=(int m);
    bigint operator/(bigint m);
    bigint operator/(int m);
    void operator/=(bigint m);
    void operator/=(int m);
    bigint operator%(bigint m);
    bigint operator%(int m);
    void operator%=(bigint m);
    void operator%=(int m);
    bigint& operator++();
    bigint operator++(int);
    bigint& operator--();
    bigint operator--(int);
    friend ostream& operator<<(ostream &out, bigint m);
    friend istream& operator>>(istream &in, bigint &m);
    string toString();
    bigint abs();
    bigint sqrt();
};

bigint& bigint::operator++() {
    *this = (*this) + 1;
    return *this;
}


bigint bigint::operator++(int) {
    bigint b = *this;
    ++(*this);
    return b;
}



bigint& bigint::operator--() {
    *this = (*this) - 1;
    return *this;
}


bigint bigint::operator--(int) {
    bigint b = *this;
    --(*this);
    return b;
}


bigint::bigint(char *s) {
    (*this) = s;
}


ostream& operator<<(ostream &out, bigint m) {
    if (m.oper == -1)
        out << "-";
    out << m.a[m.length];
    for (int i = m.length - 1; i >= 1; i--)
        out << setfill('0') << setw(4) << m.a[i];
    return out;
}


istream& operator>>(istream& in, bigint &m) {
    char s[m.maxlength * 4 + 10];
    if (!(in >> s))
        return in;
    for (int i = 0; s[i]; i++)
        if (!((s[i] >= '0' && s[i] <= '9') || ((s[i] == '+' || s[i] == '-') && i == 0)))
            in.setstate(ios::failbit);
    m = s;
    return in;
}


string bigint::toString() {
    ostringstream s;
    s << (*this);
    return s.str();
}



bigint::bigint(int v) {
    (*this) = v;
    this->check();
}


bigint::~bigint() {
}


void bigint::check() {
    for (; length > 0 && a[length] == 0; length--);
    if (length == 0)
        oper = 1;
}


void bigint::operator=(bigint m) {
    oper = m.oper;
    length = m.length;
    memcpy(a, m.a, maxlength * sizeof(int));
    this->check();
}


void bigint::operator=(int m) {
    oper = (m > 0) ? 1 : -1;
    m =::abs(m);
    memset(a, 0, maxlength * sizeof(int));
    for (length = 0; m > 0; m = m / 10000)
        a[++length] = m % 10000;
    this->check();
}


void bigint::operator=(char *s) {
    int i, L;
    (*this) = 0;
    if (s[0] == '-' || s[0] == '+') {
        if (s[0] == '-')
            oper = -1;
        L = strlen(s);
        for (i = 0; i < L; i++)
            s[i] = s[i + 1];
    }
    L = strlen(s);
    length = (L + 3) / 4;
    for (i = 0; i < L; i++)
        a[(L - i + 3) / 4] = a[(L - i + 3) / 4] * 10 + (s[i] - 48);
    this->check();
}


bool bigint::operator<(bigint m) {
    if (oper != m.oper)
        return oper < m.oper;
    if (length != m.length)
        return oper * length < m.length * oper;
    for (int i = length; i >= 1; i--)
        if (a[i] != m.a[i])
            return a[i] * oper < m.a[i] * oper;
    return false;
}


bool bigint::operator<=(bigint m) {
    return !(m < (*this));
}


bool bigint::operator>(bigint m) {
    return m < (*this);
}


bool bigint::operator>=(bigint m) {
    return !((*this) < m);
}


bool bigint::operator==(bigint m) {
    return (!((*this) < m)) && (!(m < (*this)));
}


bool bigint::operator!=(bigint m) {
    return ((*this) < m) || (m < (*this));
}


bigint bigint::operator-() {
    bigint c = (*this);
    c.oper = -c.oper;
    c.check();
    return c;
}


bigint bigint::abs() {
    bigint c = (*this);
    c.oper = int(std::abs(double(c.oper)));
    c.check();
    return c;
}


bigint bigint::operator+(bigint m) {
    if (m.length == 0)
        return (*this);
    if (length == 0)
        return m;
    if (oper == m.oper) {
        bigint c;
        c.oper = oper;
        c.length = max(length, m.length) + 1;
        for (int i = 1, temp = 0; i <= c.length; i++)
            c.a[i] = (temp = (temp / 10000 + a[i] + m.a[i])) % 10000;
        c.check();
        return c;
    }
    return (*this) - (-m);
}


bigint bigint::operator-(bigint m) {
    if (m.length == 0)
        return (*this);
    if (length == 0)
        return (-m);
    if (oper == m.oper) {
        bigint c;
        if ((*this).abs() >= m.abs()) {
            c.oper = oper;
            c.length = length;
            for (int i = 1, temp = 0; i <= length; i++)
                c.a[i] = ((temp = (-int(temp < 0) + a[i] - m.a[i])) + 10000) % 10000;
            c.check();
            return c;
        }
        return -(m - (*this));
    }
    return (*this) + (-m);
}


bigint bigint::operator*(bigint m) {
    bigint c;
    c.oper = oper * m.oper;
    c.length = length + m.length;
    for (int i = 1; i <= m.length; i++) {
        int number = m.a[i], j, temp = 0;
        for (j = 1; j <= length; j++)
            c.a[i + j - 1] += number * a[j];
        if (i % 10 == 0 || i == m.length)
            for (j = 1; j <= c.length; j++)
                c.a[j] = (temp = (temp / 10000) + c.a[j]) % 10000;
    }
    c.check();
    return c;
}


bigint bigint::operator*(int m) {
    if (m < 0)
        return -((*this) * (-m));
    if (m > 100000)
        return (*this) * bigint(m);
    bigint c;
    c.length = length + 2;
    c.oper = oper;
    int t = 0;
    for (int i = 1; i <= c.length; i++)
        c.a[i] = (t = (t / 10000 + a[i] * m)) % 10000;
    c.check();
    return c;
}


bigint bigint::operator/(bigint m) {
    if (m.length == 0) {
        cout << "Division by zero" << endl;
        exit(0);
    }
    if ((*this).abs() < m.abs())
        return 0;
    bigint c, left;
    c.oper = oper / m.oper;
    m.oper = 1;
    c.length = length - m.length + 1;
    left.length = m.length - 1;
    memcpy(left.a + 1, a + length - left.length + 1, left.length * sizeof(int));
    for (int i = c.length; i >= 1; i--) {
        left = left * 10000 + a[i];
        int head = 0, tail = 10000, mid;
        while (head + 1 < tail) {
            mid = (head + tail) / 2;
            if (m*mid <= left)
                head = mid;
            else
                tail = mid;
        }
        c.a[i] = head;
        left -= m * head;
    }
    c.check();
    return c;
}


bigint bigint::operator/(int m) {
    if (m < 0)
        return -((*this) / (-m));
    if (m > 100000)
        return (*this) / bigint(m);
    bigint c;
    c.oper = oper;
    c.length = length;
    int t = 0;
    for (int i = c.length; i >= 1; i--)
        c.a[i] = (t = (t % m * 10000 + a[i])) / m;
    c.check();
    return c;
}


bigint bigint::operator %(bigint m) {
    return (*this) - ((*this) / m) * m;
}


bigint bigint::operator%(int m) {
    if (m < 0)
        return -((*this) % (-m));
    if (m > 100000)
        return (*this) % bigint(m);
    int t = 0;
    for (int i = length; i >= 1; i--)
        t = (t * 10000 + a[i]) % m;
    return t;
}


bigint bigint::sqrt() {
    bigint m = *this;
    if (m.oper < 0 || m.length == 0)
        return 0;
    bigint c, last, now, templast;
    c.length = (m.length + 1) / 2;
    c.a[c.length] = int(std::sqrt((double)m.a[c.length * 2] * 10000 + m.a[c.length * 2 - 1]) + 1e-6);
    templast.length = c.length * 2;
    templast.a[c.length * 2 - 1] = (c.a[c.length] * c.a[c.length]) % 10000;
    templast.a[c.length * 2] = (c.a[c.length] * c.a[c.length]) / 10000;
    templast.check();
    for (int i = c.length - 1; i >= 1; i--) {
        last = templast;
        int head = 0, tail = 10000, mid, j, temp;
        while (head + 1 < tail) {
            mid = (head + tail) / 2;
            now = last;
            now.a[2 * i - 1] += mid * mid;
            for (j = i + 1; j <= c.length; j++)
                now.a[i + j - 1] += mid * c.a[j] * 2;
            now.length++;
            for (j = 2 * i - 1, temp = 0; j <= now.length; j++)
                now.a[j] = (temp = (temp / 10000 + now.a[j])) % 10000;
            now.check();
            if (now <= m) {
                templast = now;
                head = mid;
            } else
                tail = mid;
        }
        c.a[i] = head;
    }
    c.check();
    return c;
}


void bigint::operator+=(bigint m) {
    (*this) = (*this) + m;
}


void bigint::operator-=(bigint m) {
    (*this) = (*this) - m;
}


void bigint::operator*=(bigint m) {
    (*this) = (*this) * m;
}


void bigint::operator/=(bigint m) {
    (*this) = (*this) / m;
}


void bigint::operator%=(bigint m) {
    (*this) = (*this) % m;
}


void bigint::operator*=(int m) {
    (*this) = (*this) * m;
}


void bigint::operator/=(int m) {
    (*this) = (*this) / m;
}


void bigint::operator%=(int m) {
    (*this) = (*this) % m;
}
