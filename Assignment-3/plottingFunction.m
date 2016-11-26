close all;


siz=[500;
    1000;
    2000;3000];

p1s=[0.0322265625;
0.1557617188;
0.6240234375;
1.4301757812
];

p1p=[0.0087890625;
0.0429687500;
0.1665039062;
0.4008789062
];

conv=[3;4;5
];

p2s5=[1.6186523438;
2.9609375000;
4.7355957031
];


p2p5=[0.4313964844;
0.7919921875;
1.2600097656
];


p2s10=[5.0446777344;
9.2558593750;
14.7807617188
];

p2p10=[1.4382324219;
2.5212402344;
4.1149902344
];


p2s20=[19.5458984375;
35.1533203125;

56.3530273438
];

p2p20=[6.0170898438;
10.8256835938;
17.4370117188
];

p2s30=[52.0537109375;
98.3085937500;
160.4741210938
];

p2p30=[15.9335937500
28.6333007812;
45.0834960938;
];





s25=p2s5./p2p5;
s210=p2s10./p2p10;
s220=p2s20./p2p20;
s230=p2s30./p2p30;


p2sc1=[p2s5(1);p2s10(1); p2s20(1); p2s30(1) ];
p2sc2=[p2s5(2);p2s10(2); p2s20(2); p2s30(2) ];
p2sc3=[p2s5(3);p2s10(3); p2s20(3); p2s30(3) ];


p2pc1=[p2p5(1);p2p10(1); p2p20(1); p2p30(1) ];
p2pc2=[p2p5(2);p2p10(2); p2p20(2); p2p30(2) ];
p2pc3=[p2p5(3);p2p10(3); p2p20(3); p2p30(3) ];




l2=2/log(2);



col=hsv(10);
plot(l2*log(siz),p1s,'color',col(1,:),'LineWidth',2)
hold on
plot(l2*log(siz),p1p,'color',col(8,:),'LineWidth',2)
hold on
legend('serial problem 1', 'parallel problem 1')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('time (sec)');
xlabel('input size in 2*log2(n)');
ylim([0 2]);



figure

s1=p1s./p1p
col=hsv(10);
plot(l2*log(siz),s1,'color',col(1,:),'LineWidth',2)
legend('parallel implemetation')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in 2*log2(n)');
ylim([0 5]);

c2p1p1=[0.0166015625
0.0791015625;
0.3076171875;
0.7109375000];

c2p1p2=[0.8388671875;
2.6220703125;
10.8095703125;
27.7041015625];

c3p1p1=[0.0146484375;
0.0551757812;
0.2153320312;
0.4912109375
];
c3p1p2=[0.5756835938;
1.7866210938;
7.8593750000;
19.0458984375
];

figure
sp1c2=p1s./c2p1p1;
sp1c3=p1s./c3p1p1;
sp1c4=s1;
col=hsv(10);
plot(l2*log(siz),sp1c2,'color',col(1,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp1c3,'color',col(8,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp1c4,'color',col(6,:),'LineWidth',2)
    legend( '2 cores','3 cores ','4 cores')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up for problem 1 different cores');
xlabel('input size in 2*log2(n)');
ylim([0 5]);




figure
sp2c2=p2sc1./c2p1p2;
sp2c3=p2sc1./c3p1p2;
sp2c4=p2sc1./p2pc1;
col=hsv(10);
plot(l2*log(siz),sp2c2,'color',col(1,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp2c3,'color',col(8,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp2c4,'color',col(6,:),'LineWidth',2)
    legend( '2 cores','3 cores ','4 cores')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up for problem 2 different cores');
xlabel('input size in 2*log2(n)');
ylim([0 5]);





figure
sp1c2=p1s./c2p1p1;
sp1c3=p1s./c3p1p1;
sp1c4=s1;
col=hsv(10);
plot(l2*log(siz),sp1c2./2,'color',col(1,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp1c3./3,'color',col(8,:),'LineWidth',2)
hold on
plot(l2*log(siz),sp1c4./4,'color',col(6,:),'LineWidth',2)
    legend( '2 cores','3 cores ','4 cores')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('efficiency for problem 1 different cores');
xlabel('input size in 2*log2(n)');
ylim([0 2]);

s2c1=p2sc1./p2pc1;
s2c2=p2sc2./p2pc2;
s2c3=p2sc3./p2pc3;


figure
col=hsv(10);
plot(siz,s2c1,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c2,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s2c3,'color',col(9,:),'LineWidth',2)
hold on


legend('halfwidth 3','halfwidth 4','halfwidth 5')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in (n)');
ylim([3 4.5]);


figure
col=hsv(10);
plot(siz,p2sc1,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,p2pc1,'color',col(3,:),'LineWidth',2)
hold on

plot(siz,p2sc2,'color',col(4,:),'LineWidth',2)
hold on
plot(siz,p2pc2,'color',col(6,:),'LineWidth',2)
hold on

plot(siz,p2sc3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,p2pc3,'color',col(10,:),'LineWidth',2)
hold on

legend('halfwidth 3 serial','halfwidth 3 parallel','halfwidth 3 serial','halfwidth 4 parallel','halfwidth 5 serial','halfwidth 5 parallel')

ylabel('Time in seconds');
xlabel('input size in (n)');
ylim([0 200]);
figure
col=hsv(10);
plot(siz,s2c1,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c2,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s2c3,'color',col(9,:),'LineWidth',2)
hold on


legend('halfwidth 3','halfwidth 4','halfwidth 5')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in (n)');
ylim([3 4.5]);




c2p1p2=[0.8388671875;
2.6220703125;
10.8095703125;
27.7041015625];

c3p1p2=[0.5756835938;
1.7866210938;
7.8593750000;
19.0458984375
];

s2c2=p2sc1./c2p1p2;
s2c3=p2sc1./c3p1p2;
s2c4=p2sc1./p2pc1;


figure
col=hsv(10);
plot(siz,s2c2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c3,'color',col(8,:),'LineWidth',2)
hold on
plot((siz),s2c4,'color',col(6,:),'LineWidth',2)
    legend( '2 cores','3 cores ','4 cores')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up for problem 2 different cores');
xlabel('input size in (n)');
title('Only for halfwidth 3')
ylim([0 5]);


figure
col=hsv(10);
plot(siz,s2c2./2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c3./3,'color',col(8,:),'LineWidth',2)
hold on
plot((siz),s2c4./4,'color',col(6,:),'LineWidth',2)
    legend( '2 cores','3 cores ','4 cores')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up for problem 2 different cores');
xlabel('input size in (n)');
title('Only for halfwidth 3')
ylim([0 1.2]);

