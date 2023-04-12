# capasitor-power-factor-calculator-using sensor PZEM004T.
Berikut adalah penjelasan singkat mengenai kedua perhitungan tersebut:

1. Impedansi
Impedansi adalah besaran kompleks yang merepresentasikan perbandingan antara tegangan kompleks dan arus kompleks dalam sebuah rangkaian listrik. Impedansi sering disimbolkan dengan huruf Z dan diukur dalam satuan ohm. Dalam program di atas, impedansi dihitung menggunakan rumus:
Z = V / (I * cos_phi)

di mana:

V adalah tegangan (volt)
I adalah arus (ampere)
cos_phi adalah faktor daya (cosinus sudut antara tegangan dan arus)
Rumus tersebut didasarkan pada definisi impedansi dalam rangkaian listrik. Dalam hal ini, impedansi dihitung sebagai rasio antara tegangan dan arus, dan kemudian dibagi dengan faktor daya untuk mendapatkan nilai impedansi yang lebih akurat.

2.Kapasitansi
Kapasitansi adalah besaran elektrik yang mengukur kemampuan suatu konduktor untuk menyimpan muatan listrik. Kapasitansi sering disimbolkan dengan huruf C dan diukur dalam satuan farad. Dalam program di atas, kapasitansi dihitung menggunakan rumus:
C = 1 / (2 * PI * f * Z)
di mana:

f adalah frekuensi (hertz)
Z adalah impedansi (ohm)
Rumus tersebut didasarkan pada definisi kapasitansi sebagai rasio antara muatan dan tegangan, yang dapat dihitung berdasarkan impedansi dan frekuensi rangkaian listrik. Dalam hal ini, kapasitansi dihitung sebagai hasil pembagian antara 1 dan hasil kali dari 2 * PI * frekuensi dan impedansi.
