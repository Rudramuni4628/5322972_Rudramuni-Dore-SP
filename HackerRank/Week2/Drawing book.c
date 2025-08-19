int pageCount(int n, int p) {
    int from_front = p / 2;
    int from_back = (n / 2) - (p / 2);
    return (from_front < from_back) ? from_front : from_back;

}