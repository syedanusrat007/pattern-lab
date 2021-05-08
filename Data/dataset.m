C{1} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\1.png';
C{2} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\2.jpg';
C{3} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\3.jpg';
C{4} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\4.jpg';
C{5} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\5.jpg';
C{6} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\6.jpg';
C{7} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data1\7.jpg';
C{8} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\8.png';
C{9} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\9.jpg';
C{10} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\10.jpg';
C{11} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\11.jpg';
C{12} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\12.png';
C{13} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\13.jpg';
C{14} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data2\14.png';
C{15} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\15.jpg';
C{16} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\16.jpg';
C{17} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\17.png';
C{18} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\18.png';
C{19} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\19.png';
C{20} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\20.jpg';
C{21} = 'E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data3\21.jpg';



for n = 1 : 3
  I = imread(C{n});
  csvwrite('E:\MIST\L-4 T-2\CSE-444 pattern sessional\Data\data.csv', I(:).', '-append');
end