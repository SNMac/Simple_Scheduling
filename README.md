# Simple Scheduling

<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=utf-8">
<meta name=Generator content="Microsoft Word 15 (filtered)">

</head>

<div class=WordSection1>

<p class=MsoNormal><span lang=EN-US style='font-size:24.0pt'>&nbsp;</span></p>

<h2><a name="_Toc119977360"><b><span lang=EN-US style='font-size:14.0pt'>Scheduling</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>보통 일반적인 가정에서 사용하는 컴퓨터는 적게는 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>2</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>코어</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>많게는 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>8</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>코어로 구성되어 있는 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>를 탑재하고 있다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>하지만 컴퓨터는 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>8</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>개보다 훨씬 많은 수백 개의 프로세스를 실행할 수 있다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이는 운영체제의 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러가 프로세스를 얼마동안 실행할지</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>어떤 순서로 프로세스를 실행할지 결정하는 스케줄링 과정을 통해 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>자원을 여러 프로세스에게 적절히 분배하기 때문이다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이러한 작업은 굉장히 빨리 이루어지기 때문에</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용자는 마치 여러 개의 프로세스가 동시에 실행되고 있는 것처럼 느끼게 된다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'><img width=698 height=114
id="그림 2" src="README.fld/image002.png"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>8</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>코어 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'> 600</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>개가 넘는 프로세스들이 실행되고 있다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄링은 프로세스가 다음과 같은 상태 변화를 가질 때 수행된다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>1.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Waiting</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>2.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Ready</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>3.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Ready</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>4.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Terminated</span></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>상태에 있을 때 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>자원을 사용할 수 있는데</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>이때 만약 프로세스가 </span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>I/O, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>네트워크
등과 상호작용하는 작업을 수행해야 될 경우 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태로 전환되면서 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄링에서 제외된다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>프로세스가 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에서 작업을 모두 마치거나 주어진
</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사용 시간을 모두 소모하면 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>로 스케줄링 되어 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>상태가 된다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. Ready queue</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에 있는 프로세스는 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러가 우선순위 등을 고려하여 순서를 결정 후</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>차례가 되면 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>자원을 사용하게 된다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'><img width=654 height=260
id="그림 8" src="README.fld/image003.png"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ 프로세스의 생명 주기</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄링에는 비 선점형과 선점형의 두가지 기법이 있다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>비 선점형은 현재 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에 프로세스가 존재할 경우</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이 프로세스가 주어진 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>시간을 모두 소모할 때까지 다른 프로세스가 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에 도착해도 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>를 할당 할 수 없다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>선점형은 이와 반대로</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
Running </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태의 프로세스가 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>시간이 남았더라도</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>우선순위가 더 높은 프로세스가 </span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>Ready queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에
도착하면</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> Context
switching</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이 가능한 기법이다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<h2><a name="_Toc119977361"><b><span lang=EN-US style='font-size:14.0pt'>Scheduler</span></b></a></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄러는 어떤 프로세스에게 </span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을
얼마동안 할당할 것인지 결정하는 알고리즘으로</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다음과 같은 기준으로 평가할 수 있다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>1.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>대기 시간 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Ready queue</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에서 대기하는 시간</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>2.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행 시간 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스가 실행중인 시간</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>3.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>응답 시간 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>요청에 대한 프로세스의 응답이 오기까지 걸리는 시간</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>4.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환 시간 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Ready queue</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에 도착했을 때와 종료될 때까지의 시간</span></p>

<p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>5.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>단위 시간 당 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CPU</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>가 처리한 프로세스의 개수</span></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>과거에는 스케줄러의
응답 시간이 매우 길어서 키보드로 문자를 입력하면 모니터에 그 문자가 표시될 때까지 오래 걸리는 경우가 있었다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이는 특정 프로세스에 대한 키보드 입력</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>(</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>요청</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>)</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을 </span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가 처리하여 모니터로 표시</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>(</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>응답</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>)</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>하기 까지 걸리는 시간</span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉
응답 시간이 매우 길다는 것을 의미한다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라서 응답 시간은 사용자가 직접 체감할
수 있는 영역이므로 짧을 수록 좋지만</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>단순히 최소화만 한다면 </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Context switching</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이 그만큼 자주 일어나게 되므로 처리량이 그에 비해 높아지지
않을 수 있다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한 요소들에 의해 스케줄러는 응답 시간을 최소화하면서 최대의
처리량을 꾀하는 방향으로 발전하게 됐다</span><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄링 알고리즘에 대한 연구가 많이 이루어지면서 현대에는 다양한 스케줄러들이 존재하는데</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이번 과제에선 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>FIFO, RR, MLQ, MLFQ, CFS</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>로 총 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>5</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>가지의 스케줄러를 구현하였다</span><span lang=EN-US style='font-family:
"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc119977362"><b><span
lang=EN-US>FIFO(First In First Out)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US><img width=756 height=192 id="그림 9" src="README.fld/image004.png"
alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'> FIFO </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span lang=EN-US>Ready queue</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>도착한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>순서대로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행시키는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>일단</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=EN-US>Running </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어가게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span><span
lang=EN-US> CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>마칠</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span><span
lang=KO> </span><span lang=EN-US>CPU</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>를</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>점유하게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span lang=EN-US>. FIFO
</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>간단하고</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>작업이</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>짧은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>순서대로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다면</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>높다는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>장점이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>무작위로</span><span lang=KO> </span><span
lang=EN-US>Ready queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>작업이</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>긴</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>먼저</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다면</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>그</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>뒤로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>도착한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>대기</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시간은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span><span lang=KO> </span><span
lang=EN-US>Convoy effect</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>Ready queue</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span><span lang=KO> </span><span
lang=EN-US>CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>짧은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>먼저</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리하는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>비</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점형의</span><span
lang=KO> </span><span lang=EN-US>SJF(Shortest Job First), </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>선점형의</span><span lang=KO> </span><span
lang=EN-US>SRTF(Shortest Remaining Time First) </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러도</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>존재하지만</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span lang=KO> </span><span
lang=EN-US>CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>얼마나</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>소요될지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>알아내는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>것은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>어렵기</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러들은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하기</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>어렵다는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>단점이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc119977363"><b><span
lang=EN-US>RR(Round Robin)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US><img width=560 height=202 id="그림 13" src="README.fld/image005.png"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>RR </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span
lang=EN-US>Ready queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들에게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>똑같은</span><span
lang=KO> </span><span lang=EN-US>Time slice</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>할당하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span><span lang=EN-US>. Time
slice</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>특징이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>달라지는데</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>길게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정한다면</span><span
lang=KO> </span><span lang=EN-US>FIFO</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>와</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>비슷한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>장단점을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>보이지만</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>짧게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>설정한다면</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>응답</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>줄어들고</span><span lang=EN-US>
fairness</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>좋아지는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>장점을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span><span
lang=KO> </span><span lang=EN-US>Context switching</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>자주</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>일어나게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>되므로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>낮아지고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>각</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>대기</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>단점도</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>갖게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>특징으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>인해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>짧은</span><span lang=KO> </span><span
lang=EN-US>CPU </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>긴</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>작업을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>가지는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사이에서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>균형을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이루는</span><span lang=KO> </span><span
lang=EN-US>Time slice</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정하게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>현대</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제의</span><span
lang=KO> </span><span lang=EN-US>Time slice</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>는</span><span lang=KO> </span><span
lang=EN-US>10ms ~ 100ms </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc119977364"><b><span
lang=EN-US>MLQ(Multi-Level Queue)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US><img width=640 height=294 id="그림 16" src="README.fld/image006.jpg"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>MLQ </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 구조 예시</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>여러</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>독자적인</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는</span><span lang=KO> </span><span
lang=EN-US>Ready queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어진</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>각</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>는</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>서로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있으며</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>각자</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>및</span><span lang=KO> </span><span
lang=EN-US>Time slice</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>예를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>들면</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>위</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>예시에서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span
lang=EN-US> queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>RR </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄러로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>동작하고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>학생</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span lang=KO> </span><span
lang=EN-US>queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>FIFO </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>스케줄러로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>동작하는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>방식이다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하위</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가진</span><span lang=EN-US> queue</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가진</span><span lang=KO> </span><span
lang=EN-US>queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>들이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>비어</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있어야</span><span
lang=KO> </span><span lang=EN-US>Running </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>상태로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>전환된다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span><span lang=EN-US>,
Running </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있던</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>중에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>들어온다면</span><span lang=KO> </span><span
lang=EN-US>CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>반납해야</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span><span
lang=EN-US>. MLQ </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러에서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>간</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이동을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>못하므로</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span><span lang=KO> </span><span
lang=EN-US>queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>자원을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>받지</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>못하는</span><span lang=KO> </span><span
lang=EN-US>Starvation </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>현상이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>발생</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>단점이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc119977365"><b><span
lang=EN-US>MLFQ(Multi-Level Feedback Queue)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US><img width=618 height=278 id="그림 17" src="README.fld/image007.jpg"
alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>MLFQ </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span></p>

<p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'><span
lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='text-indent:5.0pt'><span lang=EN-US>MLFQ </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span><span lang=KO> </span><span
lang=EN-US>MLQ</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다르게</span><span
lang=KO> </span><span lang=EN-US>Feedback</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>통해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span><span lang=KO> </span><span
lang=EN-US>queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>간</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>허용한다</span><span
lang=EN-US>. MLFQ</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>다음과</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>같다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'><span
lang=EN-US>1.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US>Priority(A) &gt; Priority(B) </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>이면</span><span lang=EN-US>, A</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행된다</span><span lang=EN-US>.</span></p>

<p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'><span
lang=EN-US>2.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=EN-US>Priority(A) = Priority(B) </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이면</span><span lang=EN-US>, A</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span><span lang=EN-US> B</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span lang=EN-US> RR </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>방식으로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행된다</span><span lang=EN-US>.</span></p>

<p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'><span
lang=EN-US>3.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>생성되면</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>놓여진다</span><span lang=EN-US>.</span></p>

<p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'><span
lang=EN-US>4.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>주어진</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계에서</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당량을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진하면</span><span
lang=EN-US> (CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>몇</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>번</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>양도하였는지</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>상관없이</span><span
lang=EN-US>), </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>한</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이동한다</span><span lang=EN-US>.</span></p>

<p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'><span
lang=EN-US>5.<span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
</span></span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>일정</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>지나면</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span><span
lang=KO> </span><span lang=EN-US>queue</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이동한다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>보통</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮을수록</span><span
lang=EN-US> Time slice</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지도록</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정되어</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있으므로</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>위</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>따르면</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>중심의</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>내려가기</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span><span lang=KO> </span><span
lang=EN-US>CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>오랜</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간동안</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>점유할</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span><span
lang=EN-US>, I/O </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>중심의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>느리게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>내려가므로</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>중심의</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스들보다</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>교체될</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있어</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>나은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>응답</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기대할</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>일정</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>시간마다</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>최상위</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span><span lang=KO> </span><span
lang=EN-US>queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동시킴으로써</span><span
lang=KO> </span><span lang=EN-US>MLQ</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>에서</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>발생하던</span><span lang=KO> </span><span
lang=EN-US>Starvation</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>방지할</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span
lang=EN-US>.</span></p>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<h3 style='margin-left:50.0pt;text-indent:-20.0pt'><a name="_Toc119977366"><b><span
lang=EN-US>CFS(Completely Fair Scheduler)</span></b></a></h3>

<p class=MsoNormal><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=EN-US><img
width=600 height=180 id="그림 19" src="README.fld/image008.png"
alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명"></span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CFS </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 우선순위에 따른 가중치 테이블</span></p>

<p class=MsoNormal align=center style='text-align:center'><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span
lang=EN-US>CFS </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>리눅스</span><span
lang=EN-US> 2.6.23 </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>커널</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>버전</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이후</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>적용된</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>리눅스의</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>기본</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span><span
lang=EN-US>. CFS</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>100</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>부터</span><span lang=KO> </span><span lang=EN-US>139</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>까지의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>일반</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>분류하고</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>클수록</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>부여한다</span><span lang=EN-US>. </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>그리고</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스마다</span><span lang=KO> </span><span
lang=EN-US>CPU</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>점유하고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있던</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span><span
lang=KO> </span><span lang=EN-US>vruntime</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>누적</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치를</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사용해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>정규화</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>하여</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>기록해</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>놓는다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span
lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
text-indent:5.0pt'><span lang=EN-US><img width=672 height=106 id="그림 39"
src="README.fld/image009.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명"></span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
text-indent:5.0pt'><span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'> vruntime </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>계산 공식</span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
text-indent:5.0pt'><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span
lang=EN-US>vruntime</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의해</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span><span
lang=EN-US>(</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span><span
lang=EN-US>) </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>천천히</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>커지고</span><span
lang=EN-US>, </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span><span
lang=EN-US>(</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>큰</span><span
lang=EN-US>) </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>커진다</span><span
lang=EN-US>. </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span
lang=KO> </span><span lang=EN-US>vruntime</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>들은</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span lang=EN-US>ID</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>함께</span><span lang=KO> </span><span
lang=EN-US>Ready queue</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장된다</span><span
lang=EN-US>. CFS</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span><span
lang=KO> </span><span lang=EN-US>Ready queue</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>는</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러들과</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>다르게</span><span lang=KO> </span><span
lang=EN-US>Red-Black Tree</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어져</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>. Red-Black Tree</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span><span
lang=KO> </span><span lang=EN-US>Key</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>값이</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>작은</span><span lang=KO> </span><span
lang=EN-US>Value</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>부터</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>제일</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>왼쪽</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>노드에</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>위치하도록</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>정렬된</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>자료</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>구조인데</span><span
lang=EN-US>, CFS</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>에선</span><span
lang=KO> </span><span lang=EN-US>vruntime</span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>이</span><span lang=KO> </span><span lang=EN-US>Key, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span><span lang=EN-US>ID</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span><span lang=KO> </span><span
lang=EN-US>Value</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당되어</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>노드를</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>형성하고</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span><span
lang=EN-US>. CFS </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄링이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어날</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span
lang=KO> </span><span lang=EN-US>Ready Queue</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>에서</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>왼쪽</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>노드</span><span lang=EN-US>, </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span><span lang=EN-US>
vruntime</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에게</span><span
lang=KO> </span><span lang=EN-US>CPU </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>자원을</span><span lang=KO> </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>할당하게</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span><span lang=EN-US>.</span></p>

<p class=MsoNormal style='margin-left:5.0pt'><span lang=EN-US>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'><span
lang=EN-US><img width=588 height=376 id="그림 18" src="README.fld/image010.gif"></span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>CFS </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>스케줄러의 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Red-Black Tree</p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>하지만 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>vruntime</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>은 다음에 어떤 프로세스를 실행할지 조정하는 값일 뿐</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>이 값 자체가 </span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>Time slice</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>로 기능하진 않는다</span><span lang=EN-US
style='font-family:"맑은 고딕",sans-serif'>. Time slice</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>는 프로세스의 우선순위에 따라 고정된 값을 사용하게 된다</span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
text-indent:5.0pt'><span lang=EN-US style='font-family:"맑은 고딕",sans-serif'><img
width=720 height=80 id="그림 40" src="README.fld/image011.png"></span></p>

<p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
text-indent:5.0pt'><span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span><span
lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Time slice </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>계산 공식</span></p>

<span lang=EN-US style='font-size:24.0pt;font-family:"Calibri",sans-serif'><br
clear=all style='page-break-before:always'>
</span>

<h2><a name="_Toc119977368"><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>구현</span></b></a><b><span lang=KO
style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>환경</span></b><b><span lang=KO style='font-size:
14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>및</span></b><b><span
lang=KO style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:
14.0pt;font-family:"맑은 고딕",sans-serif'>실행</span></b><b><span lang=KO
style='font-size:14.0pt'> </span></b><b><span lang=KO style='font-size:14.0pt;
font-family:"맑은 고딕",sans-serif'>방법</span></b></h2>

<p class=MsoNormal><span lang=EN-US style='font-size:14.0pt'>&nbsp;</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제</span><span
lang=EN-US> : macOS</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>언어</span><span
lang=KO> </span><span lang=EN-US>: C++14</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일러</span><span
lang=KO> </span><span lang=EN-US>: clang 14.0.0</span></p>

<p class=MsoNormal><span lang=EN-US>Makefile </span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>사용하여</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>가능</span><span lang=KO> </span><span
lang=EN-US>(macOS, Linux)</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>소스</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span><span
lang=KO> </span><span lang=EN-US>: Makefile, main.h, main.cpp, Scheduler.h,
Scheduler.cpp, Process.h, Process.cpp, FIFO.h, FIFO.cpp RR.h, RR.cpp, MLQ.h,
MLQ.cpp, MLFQ.h, MLFQ.cpp, CFS.h, CFS.cpp</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>방법</span><span
lang=KO> </span><span lang=EN-US>: ./2022_os_proj1</span><span lang=KO
style='font-family:"맑은 고딕",sans-serif'>로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자의</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>입력에</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>따른</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러로</span><span lang=KO> </span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>완료</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>출력</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span><span
lang=EN-US> : &lt;</span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>이름</span><span
lang=EN-US>&gt;_schedule_dump.txt</span></p>

<p class=MsoNormal><span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span><span
lang=KO> </span><span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span><span
lang=KO> </span><span lang=EN-US>: </span><span lang=KO style='font-family:
"맑은 고딕",sans-serif'>약</span><span lang=KO> </span><span lang=EN-US>500</span><span
lang=KO style='font-family:"맑은 고딕",sans-serif'>초</span></p>

</div>

</html>
