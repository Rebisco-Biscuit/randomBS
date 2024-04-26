/* From LeetCode, Roman to Integer */

int romanToInt(char* s) {
    int len = strlen(s);
    int res = 0;
    int current[len];

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case 'I': current[i] = 1; break;
            case 'V': current[i] = 5; break;
            case 'X': current[i] = 10; break;
            case 'L': current[i] = 50; break;
            case 'C': current[i] = 100; break;
            case 'D': current[i] = 500; break;
            case 'M': current[i] = 1000; break;
            default: return 0;
        }
    }

    for (int i = 0; i < len; i++) {
        if (i + 1 < len && current[i] < current[i + 1]) {
            res -= current[i];
        } else {
            res += current[i];
        }
    }
    return res;
}
