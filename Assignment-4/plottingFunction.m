close all;


siz=[100000;
    1000000;
    10000000;
    100000000;
    1000000000];
core=[2;
    3;
    4;
    8;
    12;
    16];

p1s=[0.0046907454;

0.0349092754;

0.3442078219;

3.4319343437;

34.9319725619];

 
p1p2=[0.0020947829;

0.0193063668;

0.1871722322;

1.8737697913;

18.7037954181];

 
p1p3=[0.0014692130;

0.0141669353;

0.1378981760;

1.3670589570;

13.7071237722];

 
p1p4=[0.0011657341;

0.0108535569;

0.1062687491;

1.0578589188;

10.8943712818];

 
p1p8=[0.0007087998;

0.0058252569;

0.0554995253;

0.5478150989;

5.5034846831];

 

p1p12=[0.0043162601;

0.0108357379;

0.0625063232;

0.5322096813;

4.5690248758];

 
p1p16=[0.0021045161;

0.0071670189;

0.0571375852;

0.6486535883;

7.7207576418];

 
 p2s=[0.0004320387;

 0.0044273632;

 0.0434216950;

 0.4331330699;

 4.6783940680];

p2p2=[0.0002768589;

0.0019024308;

0.0195206110;

0.1819337183;

1.8070395123];

 p2p3=[0.0002567261;

0.0014836551;

0.0140712410;

0.1335221678;

1.3274416160];

 
p2p4=[0.0002551107;

0.0011796793;

0.0108941393;

0.1039405321;

1.0396180418];

 
p2p8=[0.0002381126;

0.0008020881;

0.0059900000;

0.0552033107;

0.5545771448];

 
p2p12=[0.0195631781;

0.0209970130;

0.0272573628;

0.0745938611;

0.5187256988];

 
p2p16=[0.0006860830;

0.0022186879;

0.0080441991;

0.0622239020;

0.5035839737];


s1c2=p1s./p1p2;
s1c3=p1s./p1p3;
s1c4=p1s./p1p4;
s1c8=p1s./p1p8;
s1c12=p1s./p1p12;
s1c16=p1s./p1p16;

s2c2=p2s./p2p2;
s2c3=p2s./p2p3;
s2c4=p2s./p2p4;
s2c8=p2s./p2p8;
s2c12=p2s./p2p12;
s2c16=p2s./p2p16;

cvs1=[s1c2(5);
    s1c3(5);
    s1c4(5);
    s1c8(5);
    s1c12(5);
    s1c16(5);
    ];
cvs2=[s2c2(5);
    s2c3(5);
    s2c4(5);
    s2c8(5);
    s2c12(5);
    s2c16(5);
    ];




siz=log(siz)

col=hsv(20);
plot(siz,p1s,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,p1p2,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,p1p3,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,p1p4,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,p1p8,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,p1p12,'color',col(12,:),'LineWidth',2)
hold on
plot(siz,p1p16,'color',col(16,:),'LineWidth',2)
hold on
title('problem 1')
legend('serial problem 1', 'parallel problem 1 core 2 ','parallel problem 1 core 3 ', 'parallel problem 1 core 4 ', 'parallel problem 1 core 8 ', 'parallel problem 1 core 12 ', 'parallel problem 1 core 16 ')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('time (sec)');
xlabel('input size in log(n)');
ylim([0 50]);



figure

col=hsv(20);
plot(siz,s1c2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s1c3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,s1c4,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s1c8,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,s1c12,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,s1c16,'color',col(12,:),'LineWidth',2)
hold on

title('problem 1')
legend('speed up core 2','speed up core 3','speed up core 4','speed up core 8','speed up core 12','speed up core 16')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in log(n)');
ylim([0 16]);
figure



col=hsv(20);
plot(siz,s1c2/2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s1c3/3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,s1c4/4,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s1c8/8,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,s1c12/12,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,s1c16/16,'color',col(12,:),'LineWidth',2)
hold on

title('problem 1')
legend('efficiency core 2','efficiency core 3','efficiency core 4','efficiency core 8','efficiency core 12','efficiency core 16')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('efficiency');
xlabel('input size in log(n)');
ylim([0 1.5]);



figure

col=hsv(20);
plot(siz,s1c2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s1c3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,s1c4,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s1c8,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,s1c12,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,s1c16,'color',col(12,:),'LineWidth',2)
hold on

title('problem 1')
legend('speed up core 2','speed up core 3','speed up core 4','speed up core 8','speed up core 12','speed up core 16')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in log(n)');
ylim([0 16]);




















figure
col=hsv(20);
plot(siz,p2s,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,p2p2,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,p2p3,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,p2p4,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,p2p8,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,p2p12,'color',col(12,:),'LineWidth',2)
hold on
plot(siz,p2p16,'color',col(16,:),'LineWidth',2)
hold on
title('problem 2')
legend('serial problem 2', 'parallel problem 2 core 2 ','parallel problem 2 core 3 ', 'parallel problem 2 core 4 ', 'parallel problem 2 core 8 ', 'parallel problem 2 core 12 ', 'parallel problem 2 core 16 ')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('time (sec)');
xlabel('input size in log(n)');
ylim([0 8]);



figure

col=hsv(20);
plot(siz,s2c2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,s2c4,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s2c8,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,s2c12,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,s2c16,'color',col(12,:),'LineWidth',2)
hold on

title('problem 2')
legend('speed up core 2','speed up core 3','speed up core 4','speed up core 8','speed up core 12','speed up core 16')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('speed up');
xlabel('input size in log(n)');
ylim([0 16]);

figure

col=hsv(20);
plot(siz,s2c2/2,'color',col(1,:),'LineWidth',2)
hold on
plot(siz,s2c3/3,'color',col(8,:),'LineWidth',2)
hold on
plot(siz,s2c4/4,'color',col(3,:),'LineWidth',2)
hold on
plot(siz,s2c8/8,'color',col(5,:),'LineWidth',2)
hold on
plot(siz,s2c12/12,'color',col(9,:),'LineWidth',2)
hold on
plot(siz,s2c16/16,'color',col(12,:),'LineWidth',2)
hold on

title('problem 2')
legend('efficiency core 2','efficiency core 3','efficiency core 4','efficiency core 8','efficiency core 12','efficiency core 16')
%title(sprintf('Red for serial \n,Blue is for inner loop thread launching\n,light blue for the outer loop threading (see the difference because of parallel overhead in launching them) \n,green for the block algorithm\n, line below the green one is block with transpose \n,Purple for Fastest parallel implementation with the row mager'))
ylabel('efficiency');
xlabel('input size in log(n)');
ylim([0 3]);


