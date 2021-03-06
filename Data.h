/*
This Source Code Form is subject to the
terms of the Mozilla Public License, v.
2.0. If a copy of the MPL was not
distributed with this file, You can
obtain one at
http://mozilla.org/MPL/2.0/.
*/

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
// Modu� z danymi
//---------------------------------------------------------------------------

struct TDist
{
    int x, y;
};
const TDist SectorOrder[] = {
    // tabela wsp�rz�dnych sektor�w, posortowana wg odleg�o�ci
    {0, 0}, // 0.00
    {1, 0}, // 1.00
    {0, 1}, // 1.00
    {1, 1}, // 1.41
    {2, 0}, // 2.00
    {0, 2}, // 2.00
    {2, 1}, // 2.24
    {1, 2}, // 2.24
    {2, 2}, // 2.83 - 9 (566m)
    {3, 0}, // 3.00
    {0, 3}, // 3.00
    {3, 1}, // 3.16
    {1, 3}, // 3.16
    {3, 2}, // 3.61
    {2, 3}, // 3.61
    {4, 0}, // 4.00 - 16 (800m)
    {0, 4}, // 4.00
    {4, 1}, // 4.12
    {1, 4}, // 4.12
    {3, 3}, // 4.24 - 20
    {4, 2}, // 4.47
    {2, 4}, // 4.47
    {4, 3}, // 5.00
    {3, 4}, // 5.00
    {5, 0}, // 5.00 - 25
    {0, 5}, // 5.00
    {5, 1}, // 5.10
    {1, 5}, // 5.10 - 28
    {5, 2}, // 5.39
    {2, 5}, // 5.39
    {4, 4}, // 5.66
    {5, 3}, // 5.83
    {3, 5}, // 5.83
    {6, 0}, // 6.00
    {0, 6}, // 6.00
    {6, 1}, // 6.08 - 36
    {1, 6}, // 6.08
    {6, 2}, // 6.32
    {2, 6}, // 6.32
    {5, 4}, // 6.40
    {4, 5}, // 6.40
    {6, 3}, // 6.71
    {3, 6}, // 6.71
    {7, 0}, // 7.00
    {0, 7}, // 7.00
    {5, 5}, // 7.07
    {7, 1}, // 7.07
    {1, 7}, // 7.07
    {6, 4}, // 7.21
    {4, 6}, // 7.21
    {7, 2}, // 7.28
    {2, 7}, // 7.28
    {7, 3}, // 7.62
    {3, 7}, // 7.62
    {6, 5}, // 7.81
    {5, 6}, // 7.81
    {8, 0}, // 8.00
    {0, 8}, // 8.00
    {7, 4}, // 8.06
    {4, 7}, // 8.06
    {8, 1}, // 8.06
    {1, 8}, // 8.06
    {8, 2}, // 8.25
    {2, 8}, // 8.25
    {6, 6}, // 8.49
    {8, 3}, // 8.54
    {3, 8}, // 8.54
    {7, 5}, // 8.60
    {5, 7}, // 8.60
    {8, 4}, // 8.94
    {4, 8}, // 8.94
    {9, 0}, // 9.00
    {0, 9}, // 9.00
    {9, 1}, // 9.06
    {1, 9}, // 9.06
    {7, 6}, // 9.22
    {6, 7}, // 9.22
    {9, 2}, // 9.22
    {2, 9}, // 9.22
    {8, 5}, // 9.43
    {5, 8}, // 9.43
    {9, 3}, // 9.49
    {3, 9}, // 9.49
    {9, 4}, // 9.85
    {4, 9}, // 9.85
    {7, 7}, // 9.90
    {8, 6}, // 10.00
    {6, 8}, // 10.00
    {10, 0}, // 10.00
    {0, 10}, // 10.00
    {10, 1}, // 10.05
    {1, 10}, // 10.05
    {10, 2}, // 10.20
    {2, 10}, // 10.20
    {9, 5}, // 10.30
    {5, 9}, // 10.30
    {10, 3}, // 10.44
    {3, 10}, // 10.44
    {8, 7}, // 10.63
    {7, 8}, // 10.63
    {10, 4}, // 10.77
    {4, 10}, // 10.77
    {9, 6}, // 10.82
    {6, 9}, // 10.82
    {11, 0}, // 11.00
    {0, 11}, // 11.00
    {11, 1}, // 11.05
    {1, 11}, // 11.05
    {10, 5}, // 11.18
    {5, 10}, // 11.18
    {11, 2}, // 11.18
    {2, 11}, // 11.18
    {8, 8}, // 11.31
    {9, 7}, // 11.40
    {7, 9}, // 11.40
    {11, 3}, // 11.40
    {3, 11}, // 11.40
    {10, 6}, // 11.66
    {6, 10}, // 11.66
    {11, 4}, // 11.70
    {4, 11}, // 11.70
    {12, 0}, // 12.00
    {0, 12}, // 12.00
    {9, 8}, // 12.04
    {8, 9}, // 12.04
    {12, 1}, // 12.04
    {1, 12}, // 12.04
    {11, 5}, // 12.08
    {5, 11}, // 12.08
    {12, 2}, // 12.17
    {2, 12}, // 12.17
    {10, 7}, // 12.21
    {7, 10}, // 12.21
    {12, 3}, // 12.37
    {3, 12}, // 12.37
    {11, 6}, // 12.53
    {6, 11}, // 12.53
    {12, 4}, // 12.65
    {4, 12}, // 12.65
    {9, 9}, // 12.73
    {10, 8}, // 12.81
    {8, 10}, // 12.81
    {12, 5}, // 13.00
    {5, 12}, // 13.00
    {13, 0}, // 13.00
    {0, 13}, // 13.00
    {11, 7}, // 13.04
    {7, 11}, // 13.04
    {13, 1}, // 13.04
    {1, 13}, // 13.04
    {13, 2}, // 13.15
    {2, 13}, // 13.15
    {13, 3}, // 13.34
    {3, 13}, // 13.34
    {12, 6}, // 13.42
    {6, 12}, // 13.42
    {10, 9}, // 13.45
    {9, 10}, // 13.45
    {11, 8}, // 13.60
    {8, 11}, // 13.60
    {13, 4}, // 13.60
    {4, 13}, // 13.60
    {12, 7}, // 13.89
    {7, 12}, // 13.89
    {13, 5}, // 13.93
    {5, 13}, // 13.93
    {14, 0}, // 14.00
    {0, 14}, // 14.00
    {14, 1}, // 14.04
    {1, 14}, // 14.04
    {10, 10}, // 14.14
    {14, 2}, // 14.14
    {2, 14}, // 14.14
    {11, 9}, // 14.21
    {9, 11}, // 14.21
    {13, 6}, // 14.32
    {6, 13}, // 14.32
    {14, 3}, // 14.32
    {3, 14}, // 14.32
    {12, 8}, // 14.42
    {8, 12}, // 14.42
    {14, 4}, // 14.56
    {4, 14}, // 14.56
    {13, 7}, // 14.76
    {7, 13}, // 14.76
    {11, 10}, // 14.87
    {10, 11}, // 14.87
    {14, 5}, // 14.87
    {5, 14}, // 14.87
    {12, 9}, // 15.00
    {9, 12}, // 15.00
    {15, 0}, // 15.00
    {0, 15}, // 15.00
    {15, 1}, // 15.03
    {1, 15}, // 15.03
    {15, 2}, // 15.13
    {2, 15}, // 15.13
    {14, 6}, // 15.23
    {6, 14}, // 15.23
    {13, 8}, // 15.26
    {8, 13}, // 15.26
    {15, 3}, // 15.30
    {3, 15}, // 15.30
    {15, 4}, // 15.52
    {4, 15}, // 15.52
    {11, 11}, // 15.56
    {12, 10}, // 15.62
    {10, 12}, // 15.62
    {14, 7}, // 15.65
    {7, 14}, // 15.65
    {13, 9}, // 15.81
    {9, 13}, // 15.81
    {15, 5}, // 15.81
    {5, 15}, // 15.81
    {16, 0}, // 16.00
    {0, 16}, // 16.00
    {16, 1}, // 16.03
    {1, 16}, // 16.03
    {14, 8}, // 16.12
    {8, 14}, // 16.12
    {16, 2}, // 16.12
    {2, 16}, // 16.12
    {15, 6}, // 16.16
    {6, 15}, // 16.16
    {12, 11}, // 16.28
    {11, 12}, // 16.28
    {16, 3}, // 16.28
    {3, 16}, // 16.28
    {13, 10}, // 16.40
    {10, 13}, // 16.40
    {16, 4}, // 16.49
    {4, 16}, // 16.49
    {15, 7}, // 16.55
    {7, 15}, // 16.55
    {14, 9}, // 16.64
    {9, 14}, // 16.64
    {16, 5}, // 16.76
    {5, 16}, // 16.76
    {12, 12}, // 16.97
    {15, 8}, // 17.00
    {8, 15}, // 17.00
    {17, 0}, // 17.00
    {0, 17}, // 17.00
    {13, 11}, // 17.03
    {11, 13}, // 17.03
    {17, 1}, // 17.03
    {1, 17}, // 17.03
    {16, 6}, // 17.09
    {6, 16}, // 17.09
    {17, 2}, // 17.12
    {2, 17}, // 17.12
    {14, 10}, // 17.20
    {10, 14}, // 17.20
    {17, 3}, // 17.26
    {3, 17}, // 17.26
    {16, 7}, // 17.46
    {7, 16}, // 17.46
    {17, 4}, // 17.46
    {4, 17}, // 17.46
    {15, 9}, // 17.49
    {9, 15}, // 17.49
    {13, 12}, // 17.69
    {12, 13}, // 17.69
    {17, 5}, // 17.72
    {5, 17}, // 17.72
    {14, 11}, // 17.80
    {11, 14}, // 17.80
    {16, 8}, // 17.89
    {8, 16}, // 17.89
    {18, 0}, // 18.00
    {0, 18}, // 18.00
    {15, 10}, // 18.03
    {10, 15}, // 18.03
    {17, 6}, // 18.03
    {6, 17}, // 18.03
    {18, 1}, // 18.03
    {1, 18}, // 18.03
    {18, 2}, // 18.11
    {2, 18}, // 18.11
    {18, 3}, // 18.25
    {3, 18}, // 18.25
    {16, 9}, // 18.36
    {9, 16}, // 18.36
    {13, 13}, // 18.38
    {17, 7}, // 18.38
    {7, 17}, // 18.38
    {14, 12}, // 18.44
    {12, 14}, // 18.44
    {18, 4}, // 18.44
    {4, 18}, // 18.44
    {15, 11}, // 18.60
    {11, 15}, // 18.60
    {18, 5}, // 18.68
    {5, 18}, // 18.68
    {17, 8}, // 18.79
    {8, 17}, // 18.79
    {16, 10}, // 18.87
    {10, 16}, // 18.87
    {18, 6}, // 18.97
    {6, 18}, // 18.97
    {19, 0}, // 19.00
    {0, 19}, // 19.00
    {19, 1}, // 19.03
    {1, 19}, // 19.03
    {14, 13}, // 19.10
    {13, 14}, // 19.10
    {19, 2}, // 19.10
    {2, 19}, // 19.10
    {15, 12}, // 19.21
    {12, 15}, // 19.21
    {17, 9}, // 19.24
    {9, 17}, // 19.24
    {19, 3}, // 19.24
    {3, 19}, // 19.24
    {18, 7}, // 19.31
    {7, 18}, // 19.31
    {16, 11}, // 19.42
    {11, 16}, // 19.42
    {19, 4}, // 19.42
    {4, 19}, // 19.42
    {19, 5}, // 19.65
    {5, 19}, // 19.65
    {18, 8}, // 19.70
    {8, 18}, // 19.70
    {17, 10}, // 19.72
    {10, 17}, // 19.72
    {14, 14}, // 19.80
    {15, 13}, // 19.85
    {13, 15}, // 19.85
    {19, 6}, // 19.92
    {6, 19}, // 19.92
    {16, 12}, // 20.00
    {12, 16}, // 20.00
    {18, 9}, // 20.12
    {9, 18}, // 20.12
    {17, 11}, // 20.25
    {11, 17}, // 20.25
    {19, 7}, // 20.25
    {7, 19}, // 20.25
    {15, 14}, // 20.52
    {14, 15}, // 20.52
    {18, 10}, // 20.59
    {10, 18}, // 20.59
    {16, 13}, // 20.62
    {13, 16}, // 20.62
    {19, 8}, // 20.62
    {8, 19}, // 20.62
    {17, 12}, // 20.81
    {12, 17}, // 20.81
    {19, 9}, // 21.02
    {9, 19}, // 21.02
    {18, 11}, // 21.10
    {11, 18}, // 21.10
    {15, 15}, // 21.21
    {16, 14}, // 21.26
    {14, 16}, // 21.26
    {17, 13}, // 21.40
    {13, 17}, // 21.40
    {19, 10}, // 21.47
    {10, 19}, // 21.47
    {18, 12}, // 21.63
    {12, 18}, // 21.63
    {16, 15}, // 21.93
    {15, 16}, // 21.93
    {19, 11}, // 21.95
    {11, 19}, // 21.95
    {17, 14}, // 22.02
    {14, 17}, // 22.02
    {18, 13}, // 22.20
    {13, 18}, // 22.20
    {19, 12}, // 22.47
    {12, 19}, // 22.47
    {16, 16}, // 22.63
    {17, 15}, // 22.67
    {15, 17}, // 22.67
    {18, 14}, // 22.80
    {14, 18}, // 22.80
    {19, 13}, // 23.02
    {13, 19}, // 23.02
    {17, 16}, // 23.35
    {16, 17}, // 23.35
    {18, 15}, // 23.43
    {15, 18}, // 23.43
    {19, 14}, // 23.60
    {14, 19}, // 23.60
    {17, 17}, // 24.04
    {18, 16}, // 24.08
    {16, 18}, // 24.08
    {19, 15}, // 24.21
    {15, 19}, // 24.21
    {18, 17}, // 24.76
    {17, 18}, // 24.76
    {19, 16}, // 24.84
    {16, 19}, // 24.84
    {18, 18}, // 25.46
    {19, 17}, // 25.50
    {17, 19}, // 25.50
    {19, 18}, // 26.17
    {18, 19}, // 26.17
    {19, 19} // 26.87 - 400 (5374m)
};

#endif
