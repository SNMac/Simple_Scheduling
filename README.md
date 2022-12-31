# Simple Scheduling

<html>

<head>
    <meta http-equiv=Content-Type content="text/html; charset=utf-8">
    <meta name=Generator content="Microsoft Word 15 (filtered)">
    
</head>


    <div class=WordSection1>



        <p class=MsoNormal>
            <span lang=EN-US style='font-size:24.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977360">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>Scheduling</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>보통 일반적인 가정에서 사용하는 컴퓨터는 적게는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>2</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>코어</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많게는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>8</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코어로 구성되어 있는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 탑재하고 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>하지만 컴퓨터는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>8</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개보다 훨씬 많은 수백 개의 프로세스를 실행할 수 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이는 운영체제의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러가 프로세스를 얼마동안 실행할지</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>어떤 순서로 프로세스를 실행할지 결정하는 스케줄링 과정을 통해 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을 여러 프로세스에게 적절히 분배하기 때문이다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한 작업은 굉장히 빨리 이루어지기 때문에</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자는 마치 여러 개의 프로세스가 동시에 실행되고 있는 것처럼 느끼게 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=349 height=57 id="그림 2" src="README.fld/image002.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>8</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>코어 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> 600</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개가 넘는 프로세스들이 실행되고 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄링은 프로세스가 다음과 같은 상태 변화를 가질 때 수행된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                1.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                2.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                3.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                4.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>→ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Terminated</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에 있을 때 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을 사용할 수 있는데</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이때 만약 프로세스가 </span>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>I/O, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>네트워크
            등과 상호작용하는 작업을 수행해야 될 경우 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태로 전환되면서 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄링에서 제외된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Waiting
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에서 작업을 모두 마치거나 주어진
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용 시간을 모두 소모하면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 스케줄링 되어 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태가 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 있는 프로세스는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러가 우선순위 등을 고려하여 순서를 결정 후</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>차례가 되면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을 사용하게 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=327 height=130 id="그림 8" src="README.fld/image003.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ 프로세스의 생명 주기</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄링에는 비 선점형과 선점형의 두가지 기법이 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>비 선점형은 현재 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에 프로세스가 존재할 경우</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이 프로세스가 주어진 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을 모두 소모할 때까지 다른 프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 도착해도 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 할당 할 수 없다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>선점형은 이와 반대로</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태의 프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이 남았더라도</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>우선순위가 더 높은 프로세스가 </span>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에
            도착하면</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> Context
            switching</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이 가능한 기법이다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977361">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>Scheduler</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄러는 어떤 프로세스에게 </span>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자원을
            얼마동안 할당할 것인지 결정하는 알고리즘으로</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다음과 같은 기준으로 평가할 수 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                1.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>대기 시간 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서 대기하는 시간</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                2.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행 시간 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 실행중인 시간</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                3.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>응답 시간 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>요청에 대한 프로세스의 응답이 오기까지 걸리는 시간</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                4.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>반환 시간 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 도착했을 때와 종료될 때까지의 시간</span>
        </p>

        <p class=MsoListParagraph style='margin-left:41.0pt;text-indent:-18.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                5.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>: </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단위 시간 당 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가 처리한 프로세스의 개수</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과거에는 스케줄러의
            응답 시간이 매우 길어서 키보드로 문자를 입력하면 모니터에 그 문자가 표시될 때까지 오래 걸리는 경우가 있었다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이는 특정 프로세스에 대한 키보드 입력</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>요청</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>)</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가 처리하여 모니터로 표시</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>응답</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>)</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>하기 까지 걸리는 시간</span>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉
            응답 시간이 매우 길다는 것을 의미한다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라서 응답 시간은 사용자가 직접 체감할
            수 있는 영역이므로 짧을 수록 좋지만</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단순히 최소화만 한다면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Context switching</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이 그만큼 자주 일어나게 되므로 처리량이 그에 비해 높아지지
            않을 수 있다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한 요소들에 의해 스케줄러는 응답 시간을 최소화하면서 최대의
            처리량을 꾀하는 방향으로 발전하게 됐다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄링 알고리즘에 대한 연구가 많이 이루어지면서 현대에는 다양한 스케줄러들이 존재하는데</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이번 과제에선 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>FIFO, RR, MLQ, MLFQ, CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 총 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>5</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>가지의 스케줄러를 구현하였다</span>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977362">
                <b>
                    <span lang=EN-US>FIFO(First In First Out)</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=378 height=96 id="그림 9" src="README.fld/image004.png" alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> FIFO </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span>
            <a href="#_edn1" name="_ednref1" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:8.0pt;font-family:
                            "맑은 고딕",sans-serif'>[i]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif;color:black;background:
            white'>(tistory, 2019)</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>순서대로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행시키는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일단</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어가게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span>
            <span lang=EN-US> CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>마칠</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>점유하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. FIFO
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>간단하고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>작업이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>짧은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>순서대로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>장점이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>무작위로</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>작업이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>긴</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>먼저</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>그</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>뒤로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>대기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span>
            <span lang=KO></span>
            <span lang=EN-US>Convoy effect</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>짧은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>먼저</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점형의</span>
            <span lang=KO></span>
            <span lang=EN-US>SJF(Shortest Job First), </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점형의</span>
            <span lang=KO></span>
            <span lang=EN-US>SRTF(Shortest Remaining Time First) </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재하지만</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>얼마나</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소요될지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>알아내는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>어렵기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>어렵다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단점이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977363">
                <b>
                    <span lang=EN-US>RR(Round Robin)</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=280 height=101 id="그림 13" src="README.fld/image005.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>RR </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span>
            <a href="#_edn2" name="_ednref2" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:"맑은 고딕",sans-serif'>[ii]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif;color:black;
            background:white'>(velog, 2021)</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들에게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>똑같은</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span>
            <span lang=EN-US>. Time
            slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>특징이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>달라지는데</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>길게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정한다면</span>
            <span lang=KO></span>
            <span lang=EN-US>FIFO</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비슷한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>장단점을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보이지만</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>짧게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정한다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>응답</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>줄어들고</span>
            <span lang=EN-US>
            fairness</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>좋아지는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>장점을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span>
            <span lang=KO></span>
            <span lang=EN-US>Context switching</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자주</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어나게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되므로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리량이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮아지고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>대기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단점도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>특징으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>인해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제로는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>짧은</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>긴</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>작업을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>균형을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루는</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현대</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>10ms ~ 100ms </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977364">
                <b>
                    <span lang=EN-US>MLQ(Multi-Level Queue)</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=320 height=147 id="그림 16" src="README.fld/image006.jpg">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 구조 예시</span>
            <a href="#_edn3" name="_ednref3" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:"맑은 고딕",sans-serif'>[iii]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif;color:black;
            background:white'>(blogspot, 2019)</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>여러</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>독자적인</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지는</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어진</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>서로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있으며</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각자</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>및</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>예를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들면</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>예시에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시스템</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US> queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>RR </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄러로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>동작하고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>학생</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>FIFO </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄러로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>동작하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방식이다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진</span>
            <span lang=EN-US> queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있어야</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>상태로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전환된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>,
            Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>중에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어온다면</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>반납해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span>
            <span lang=EN-US>. MLQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>간</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못하므로</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>자원을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못하는</span>
            <span lang=KO></span>
            <span lang=EN-US>Starvation </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현상이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>발생</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단점이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977365">
                <b>
                    <span lang=EN-US>MLFQ(Multi-Level Feedback Queue)</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=309 height=139 id="그림 17" src="README.fld/image007.jpg" alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLFQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 동작 방식</span>
            <a href="#_edn4" name="_ednref4" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:"맑은 고딕",sans-serif'>[iv]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>(blogspot,
            2019)</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>MLFQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span>
            <span lang=KO></span>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다르게</span>
            <span lang=KO></span>
            <span lang=EN-US>Feedback</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>간</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>허용한다</span>
            <span lang=EN-US>. MLFQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다음과</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'>
            <span lang=EN-US>
                1.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US>Priority(A) &gt; Priority(B) </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이면</span>
            <span lang=EN-US>, A</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'>
            <span lang=EN-US>
                2.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=EN-US>Priority(A) = Priority(B) </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이면</span>
            <span lang=EN-US>, A</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=EN-US> B</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=EN-US> RR </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방식으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'>
            <span lang=EN-US>
                3.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생성되면</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>놓여진다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'>
            <span lang=EN-US>
                4.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>주어진</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당량을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진하면</span>
            <span lang=EN-US> (CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>몇</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>번</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>양도하였는지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상관없이</span>
            <span lang=EN-US>), </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동한다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoListParagraph style='margin-left:48.0pt;text-indent:-18.0pt'>
            <span lang=EN-US>
                5.
                <span style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;
                </span>
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일정</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>지나면</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동한다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보통</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮을수록</span>
            <span lang=EN-US> Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>길어지도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정되어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있으므로</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따르면</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>중심의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>내려가기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>오랜</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간동안</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>점유할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span>
            <span lang=EN-US>, I/O </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>중심의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>느리게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>내려가므로</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>중심의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들보다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>교체될</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>나은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>응답</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기대할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일정</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간마다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>최상위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동시킴으로써</span>
            <span lang=KO></span>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>발생하던</span>
            <span lang=KO></span>
            <span lang=EN-US>Starvation</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방지할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977366">
                <b>
                    <span lang=EN-US>CFS(Completely Fair Scheduler)</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=300 height=90 id="그림 19" src="README.fld/image008.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 우선순위에 따른 가중치 테이블</span>
            <a href="#_edn5" name="_ednref5" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:
                            "맑은 고딕",sans-serif'>[v]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>(bootlin, n.d.)</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=EN-US>CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>리눅스</span>
            <span lang=EN-US> 2.6.23 </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>커널</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>버전</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>적용된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>리눅스의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기본</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이다</span>
            <span lang=EN-US>. CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>100</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>부터</span>
            <span lang=KO></span>
            <span lang=EN-US>139</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>까지의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일반</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>분류하고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>클수록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부여한다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>그리고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스마다</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>점유하고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>누적</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>정규화</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기록해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>놓는다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=336 height=53 id="그림 39" src="README.fld/image009.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> vruntime </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계산 공식</span>
            <a href="#_edn6" name="_ednref6" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:"맑은 고딕",sans-serif'>[vi]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>(egloos,
            2019)</span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=EN-US>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span>
            <span lang=EN-US>) </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>천천히</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>커지고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=EN-US>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>큰</span>
            <span lang=EN-US>) </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>빠르게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>커진다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>함께</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장된다</span>
            <span lang=EN-US>. CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러들과</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다르게</span>
            <span lang=KO></span>
            <span lang=EN-US>Red-Black Tree</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어져</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. Red-Black Tree</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>Key</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>값이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span>
            <span lang=KO></span>
            <span lang=EN-US>Value</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부터</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>제일</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>왼쪽</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>노드에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>위치하도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>정렬된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자료</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구조인데</span>
            <span lang=EN-US>, CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에선</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=EN-US>Key, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=EN-US>Value</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당되어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>노드를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>형성하고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄링이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어날</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>왼쪽</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>노드</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>즉</span>
            <span lang=EN-US>
            vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에게</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>자원을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'>
            <span lang=EN-US>
                <img width=294 height=188 id="그림 18" src="README.fld/image010.gif">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                Red-Black Tree
                <a href="#_edn7" name="_ednref7" title="">
                    <span class=MsoEndnoteReference>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:
                            "맑은 고딕",sans-serif'>[vii]</span>
                        </span>
                    </span>
                </a>
            </span>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>(uzoogom, 2010)</span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은 다음에 어떤 프로세스를 실행할지 조정하는 값일 뿐</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이 값 자체가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 기능하진 않는다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는 프로세스의 우선순위에 따라 고정된 값을 사용하게 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=360 height=40 id="그림 40" src="README.fld/image011.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Time slice </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계산 공식</span>
            <a href="#_edn8" name="_ednref8" title="">
                <span class=MsoEndnoteReference>
                    <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                        <span class=MsoEndnoteReference>
                            <span lang=EN-US style='font-size:10.0pt;font-family:"맑은 고딕",sans-serif'>[viii]</span>
                        </span>
                    </span>
                </span>
            </a>
            <span lang=EN-US style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>(egloos,
            2019)</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <span lang=EN-US style='font-size:24.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:24.0pt'>&nbsp;</span>
        </p>

        <h1>
            <a name="_Toc119977367">
                <b>
                    <span lang=EN-US style='font-size:24.0pt;
                    font-family:"Calibri",sans-serif'>Implementation</span>
                </b>
            </a>
        </h1>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:24.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977368">
                <b>
                    <span lang=KO style='font-size:14.0pt;
                    font-family:"맑은 고딕",sans-serif'>구현</span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;
                font-family:"맑은 고딕",sans-serif'>환경</span>
            </b>
            <b>
                <span lang=KO style='font-size:
                14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>및</span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:
                14.0pt;font-family:"맑은 고딕",sans-serif'>실행</span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;
                font-family:"맑은 고딕",sans-serif'>방법</span>
            </b>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>운영체제</span>
            <span lang=EN-US> : macOS</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>언어</span>
            <span lang=KO></span>
            <span lang=EN-US>: C++14</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일러</span>
            <span lang=KO></span>
            <span lang=EN-US>: clang 14.0.0</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>Makefile </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용하여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>컴파일</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가능</span>
            <span lang=KO></span>
            <span lang=EN-US>(macOS, Linux)</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소스</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span>
            <span lang=KO></span>
            <span lang=EN-US>: Makefile, main.h, main.cpp, Scheduler.h,
            Scheduler.cpp, Process.h, Process.cpp, FIFO.h, FIFO.cpp RR.h, RR.cpp, MLQ.h,
            MLQ.cpp, MLFQ.h, MLFQ.cpp, CFS.h, CFS.cpp</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방법</span>
            <span lang=KO></span>
            <span lang=EN-US>: ./2022_os_proj1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>입력에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>완료</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>출력</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>파일</span>
            <span lang=EN-US> : &lt;</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이름</span>
            <span lang=EN-US>&gt;_schedule_dump.txt</span>
        </p>

        <p class=MsoNormal>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간</span>
            <span lang=KO></span>
            <span lang=EN-US>: </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>약</span>
            <span lang=KO></span>
            <span lang=EN-US>500</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977369">
                <b>
                    <span lang=KO style='font-size:14.0pt;
                    font-family:"맑은 고딕",sans-serif'>프로그램</span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;
                font-family:"맑은 고딕",sans-serif'>구조</span>
            </b>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=210 height=105 id="그림 20" src="README.fld/image012.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ 프로그램의 소스 파일 구조</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:10.0pt;text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>본</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램은</span>
            <span lang=KO></span>
            <span lang=EN-US>main, Process, Scheduler, FIFO, RR, MLQ, MLFQ, CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이루어져</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. main</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=EN-US>10</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각각</span>
            <span lang=KO></span>
            <span lang=EN-US>0 ~ 19 </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>사이의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>난수를</span>
            <span lang=KO></span>
            <span lang=EN-US>priority </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당한다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>그리고</span>
            <span lang=KO></span>
            <span lang=EN-US>50ms</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>마다</span>
            <span lang=KO></span>
            <span lang=EN-US>SIGALRM </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>신호를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생성</span>
            <span lang=EN-US>, signal_handler</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span>
            <span lang=KO></span>
            <span lang=EN-US>SIGUSR1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전송한다</span>
            <span lang=EN-US>. Process</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>프로세스에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행되는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드로</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>최초</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실행</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>IO_burst</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>10 ~ 200 </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>난수로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>, SIGUSR1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때마다</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>씩</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>감소시키고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=EN-US>0</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span>
            <span lang=KO></span>
            <span lang=EN-US>main</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에게</span>
            <span lang=KO></span>
            <span lang=EN-US>Message
            Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span>
            <span lang=KO></span>
            <span lang=EN-US>I/O</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>요청한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>IO_burst</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>난수로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다시</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는다</span>
            <span lang=EN-US>.
            Scheduler</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용자가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선택한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>데이터에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>접근하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기능을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하며</span>
            <span lang=EN-US>, FIFO, RR, MLQ, MLFQ, CFS</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>필요한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자료구조와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>함수가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선언되어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>.</span>
        </p>

        <span lang=EN-US style='font-size:14.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977370">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>IPC(Inter-Process
                    Communication)</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977371">
                <b>
                    <span lang=EN-US>Signal</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=239 height=99 id="그림 21" src="README.fld/image013.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>main.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>sigaction()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=277 height=128 id="그림 22" src="README.fld/image014.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> main.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>setitimer()</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>main</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>sigaction()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을 통해 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>SIGALRM</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 대한 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>signal_handler</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 설정하고</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, setitimer()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>50ms</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>마다 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>SIGALRM</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을 수신하게 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=335 height=99 id="그림 24" src="README.fld/image015.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> main.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>signal_handler() </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일부</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>SIGALRM</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을
            수신하면 현재 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에 있는 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에게 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>SIGUSR1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을 보내 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>1 </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>감소시킨다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에도 프로세스가 있는 경우</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 속한 모든 프로세스의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>IO_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>1</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>씩 감소시킨다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=452 height=68 id="그림 28" src="README.fld/image016.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Process.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>signal_handler() </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일부</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>SIGUSR1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을
            수신한 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는 자신의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>1 </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>감소시킨 후</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>0</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이라면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>I/O
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작업을 위해 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>main</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Message Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>I/O </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>요청을 보낸다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h3 style='margin-left:50.0pt;text-indent:-20.0pt'>
            <a name="_Toc119977372">
                <b>
                    <span lang=EN-US>Message Queue</span>
                </b>
            </a>
        </h3>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=244 height=117 id="그림 25" src="README.fld/image017.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Message Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>main </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에 전송할 데이터</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=247 height=71 id="그림 26" src="README.fld/image018.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Process.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>sendMsg()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US style='font-family:
            "맑은 고딕",sans-serif'>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스는
            </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>SIGUSR1</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을 수신할 때마다 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>msgsnd()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 통해 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>IO_burst </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간과 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>isIOJob </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을 보내게 된다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>. </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>만약 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>0</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이라면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>isIOJob</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>true</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>아니면 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>false</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를 할당한다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
                <img width=337 height=171 id="그림 29" src="README.fld/image019.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>main.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 무한 루프문</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=left style='text-align:left;text-indent:5.0pt'>
            <span lang=EN-US>main</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=EN-US>signal_handler()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수행중인</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>제외하곤</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로부터</span>
            <span lang=KO></span>
            <span lang=EN-US>Message Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>msgblock</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착했는지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>무한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>루프</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>속에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계속</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>확인한다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도착한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span>
            <span lang=EN-US>, msgblock</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>isIOJob</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=EN-US>true</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>중인</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보내고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>아니면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>남은</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>확인</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>Inactive
            queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보내거나</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계속</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>진행한다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977373">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>FIFO</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=246 height=105 id="그림 30" src="README.fld/image020.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>FIFO.h</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US> FIFO </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>클래스의</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각각</span>
            <span lang=KO></span>
            <span lang=EN-US>std::queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>std::vector</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현되어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>. now_pid</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>첫번째</span>
            <span lang=KO></span>
            <span lang=EN-US>pid</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의미한다</span>
            <span lang=EN-US>.
            child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>최초에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>한번</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어가면</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전부</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span>
            <span lang=KO></span>
            <span lang=EN-US>now_pid</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>변경되지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다</span>
            <span lang=EN-US>. CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진하면</span>
            <span lang=KO></span>
            <span lang=EN-US>waitQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되어</span>
            <span lang=KO></span>
            <span lang=EN-US>IO_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전부</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때까지</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977374">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>RR</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>
                <img width=222 height=170 id="그림 6" src="README.fld/image021.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>RR.h</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>RR </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>클래스는</span>
            <span lang=KO></span>
            <span lang=EN-US>FIFO </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>클래스에서</span>
            <span lang=KO></span>
            <span lang=EN-US>std::queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>inactiveQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>추가된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>형태이다</span>
            <span lang=EN-US>.
            Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다시</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되던</span>
            <span lang=KO></span>
            <span lang=EN-US>FIFO</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>달리</span>
            <span lang=EN-US>, RR</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=EN-US>inactiveQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있고</span>
            <span lang=KO></span>
            <span lang=EN-US>inactiveQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다면</span>
            <span lang=EN-US>, swap()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>서로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>내용을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>교환하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. RR</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>50 tick</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정하였다</span>
            <span lang=EN-US>.</span>
        </p>

        <span lang=EN-US style='font-size:14.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977375">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>MLQ</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>
                <img width=413 height=283 id="그림 82" src="README.fld/image022.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLQ.h</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>본</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고정된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개수인</span>
            <span lang=KO></span>
            <span lang=EN-US>10</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>개의</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄링</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것이므로</span>
            <span lang=KO></span>
            <span lang=EN-US>MLQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>레벨은</span>
            <span lang=KO></span>
            <span lang=EN-US>3</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가정하였다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>표현하기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>위해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>각각</span>
            <span lang=KO></span>
            <span lang=EN-US>3</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>개의</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue, Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=EN-US> now_pid</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>나타내는</span>
            <span lang=KO></span>
            <span lang=EN-US>now_level</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갖고있다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위인</span>
            <span lang=KO></span>
            <span lang=EN-US>readyFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>50 tick, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>두번째</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위인</span>
            <span lang=KO></span>
            <span lang=EN-US>readySecondQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>75 tick, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>마지막</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위인</span>
            <span lang=KO></span>
            <span lang=EN-US>readyThirdQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=EN-US> Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>100 tick</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt;
        text-autospace:ideograph-numeric ideograph-other;word-break:keep-all'>
            <span lang=EN-US>
                <img width=252 height=113 id="그림 3" src="README.fld/image023.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Scheduler.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>insertReadyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 일부분</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>priority</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>0</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>부터</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>
            5</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>까지</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>, 6</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부터 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>12</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>까지</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>,
            13</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부터</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'> 19</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>까지로 우선순위를 나눠서 각 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>readyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하였다</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>.</span>
        </p>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>
                <img width=177 height=140 id="그림 83" src="README.fld/image024.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLQ.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>setNowPID()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>
                <img width=343 height=327 id="그림 85" src="README.fld/image025.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Scheduler.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>WaitQtoReadyQ()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 일부분</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt;text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span>
            <span lang=KO></span>
            <span lang=EN-US>queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스에</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당하지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당되어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있었다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점하여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가져오는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러이므로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해당</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>front()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>now_pid, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=EN-US>now_level</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정하도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하였다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>, waitQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=EN-US>IO_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진한</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>확인할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하위</span>
            <span lang=KO></span>
            <span lang=EN-US>waitQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부터</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>확인하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방식으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하여</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상위</span>
            <span lang=KO></span>
            <span lang=EN-US>waitQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>발견했을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span>
            <span lang=EN-US>
            now_pid</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>바로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전환하도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성했다</span>
            <span lang=EN-US>.</span>
        </p>

        <span lang=EN-US style='font-size:14.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977376">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>MLFQ</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=341 height=285 id="그림 33" src="README.fld/image026.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLFQ.h</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>MLFQ </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>클래스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>앞선</span>
            <span lang=KO></span>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>별로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>남아있는</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장하는</span>
            <span lang=KO></span>
            <span lang=EN-US>Hash map</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>인</span>
            <span lang=KO></span>
            <span lang=EN-US>std::unordered_map</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현된</span>
            <span lang=KO></span>
            <span lang=EN-US>childRemainTs</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기화</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>세는</span>
            <span lang=KO></span>
            <span lang=EN-US>afterResetTime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>추가된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>형태이다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=208 height=230 id="그림 34" src="README.fld/image027.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLFQ.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>resetPriority()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처음</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들어지면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가장</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진</span>
            <span lang=KO></span>
            <span lang=EN-US>readyFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>되어</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기다린다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만약</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자신의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>차례가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>됐을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>동안</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진하지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못했다면</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>한단계</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>되면서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>새로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는다</span>
            <span lang=EN-US>. CPU_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진했다면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계의</span>
            <span lang=KO></span>
            <span lang=EN-US>Wait queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되었다가</span>
            <span lang=KO></span>
            <span lang=EN-US>IO_burst</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전부</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다시</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>단계의</span>
            <span lang=KO></span>
            <span lang=EN-US>Ready queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하지만</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>새로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받는게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>아닌</span>
            <span lang=EN-US>, childRemainTs</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>남아있던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이어서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>, 900 tick</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>마다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>프로세스들은</span>
            <span lang=KO></span>
            <span lang=EN-US>readyFirstQ
            </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>혹은</span>
            <span lang=KO></span>
            <span lang=EN-US>waitFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기화된다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이러한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과정을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>통해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>앞에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설명했던</span>
            <span lang=KO></span>
            <span lang=EN-US>MLFQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙</span>
            <span lang=KO></span>
            <span lang=EN-US>5</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만족하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977377">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>CFS</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=286 height=230 id="그림 35" src="README.fld/image028.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS.h</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>클래스는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>미리</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계산</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되어있는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>테이블인</span>
            <span lang=KO></span>
            <span lang=EN-US>sched_prio_to_weight</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>프로세스의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장하는</span>
            <span lang=KO></span>
            <span lang=EN-US>Hash map pidWeights, vruntime</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장하는</span>
            <span lang=EN-US> Hash map</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>인</span>
            <span lang=KO></span>
            <span lang=EN-US>pidVruntime, Red-Black Tree </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>자료구조인</span>
            <span lang=KO></span>
            <span lang=EN-US>std::multimap</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구성된</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ, std::queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구성된</span>
            <span lang=KO></span>
            <span lang=EN-US>inactiveQ, std::vector</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구성된</span>
            <span lang=KO></span>
            <span lang=EN-US>waitQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가진다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>본</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고정된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>숫자인</span>
            <span lang=KO></span>
            <span lang=EN-US>10</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>개의</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스만</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재한다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가정했으므로</span>
            <span lang=KO></span>
            <span lang=EN-US>sched_prio_to_weight</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상황에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>맞게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수정하여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용하였다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=400 height=54 id="그림 36" src="README.fld/image029.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>Scheduler.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 최초 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>ID </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>삽입 함수인 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>insertReadyQ()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부분</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>최초에</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생성되고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>insert()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>될</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=EN-US>sched_prio_to_weight</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>priority </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>인덱스에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해당하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가져와</span>
            <span lang=KO></span>
            <span lang=EN-US>pidWeights</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장한다</span>
            <span lang=EN-US>. pidVruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기값이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=EN-US>0</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이므로</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값으로도</span>
            <span lang=KO></span>
            <span lang=EN-US>0</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>넣는다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='margin-left:5.0pt;text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=393 height=48 id="그림 37" src="README.fld/image030.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>updateVruntime()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>한</span>
            <span lang=EN-US> tick</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>지날</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때마다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>현재</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갱신하는데</span>
            <span lang=EN-US>, readyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갱신된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>바로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>순서가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>바뀔</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따로</span>
            <span lang=KO></span>
            <span lang=EN-US>pidVruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>저장하도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하였다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>갱신된</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=EN-US>waitQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이동할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>혹은</span>
            <span lang=KO></span>
            <span lang=EN-US>inactiveQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>와</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>바꾸는</span>
            <span lang=KO></span>
            <span lang=EN-US>swapQ()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>호출할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=EN-US>readyQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스</span>
            <span lang=EN-US>ID</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=EN-US>insert()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하면서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성된다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=376 height=79 id="그림 38" src="README.fld/image031.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS.cpp</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의 </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>getTimeSlice()</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center;text-indent:5.0pt'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>앞서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설명했듯이</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>로는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>기능하지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라서</span>
            <span lang=KO></span>
            <span lang=EN-US>Context switching</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어날</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때마다</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계산해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>한다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>본</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램에선</span>
            <span lang=KO></span>
            <span lang=EN-US>child </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스들의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>최초</span>
            <span lang=EN-US> 0 ~ 19 </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>난수로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>주어진</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이후</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>별다른</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수정이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가해지지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상황을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가정하여서</span>
            <span lang=EN-US>, Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처음</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>계산한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>변경되진</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <span lang=EN-US style='font-size:24.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US style='font-size:24.0pt'>&nbsp;</span>
        </p>

        <h1>
            <a name="_Toc119977378">
                <b>
                    <span lang=EN-US style='font-size:24.0pt;
                    font-family:"Calibri",sans-serif'>Conclusion</span>
                </b>
            </a>
        </h1>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:24.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977379">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>MLQ,
                    MLFQ, CFS </span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:14.0pt;font-family:
                "맑은 고딕",sans-serif'>결과</span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;font-family:"맑은 고딕",sans-serif'>분석</span>
            </b>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=174 height=116 id="그림 4" src="README.fld/image032.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLQ CPU time</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>결과를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보면</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=KO></span>
            <span lang=EN-US>readySecondQ, readyThirdQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>속해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있던</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들은</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전혀</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못하는</span>
            <span lang=KO></span>
            <span lang=EN-US>Starvation </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태였거나</span>
            <span lang=EN-US>, readyFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>속한</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>들에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>적은</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU time</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가졌던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태였던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>알</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=181 height=116 id="그림 7" src="README.fld/image033.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>MLFQ CPU time</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span>
            <span lang=KO></span>
            <span lang=EN-US>MLFQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>들이</span>
            <span lang=KO></span>
            <span lang=EN-US>MLQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>매우</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고르게</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU time</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가졌고</span>
            <span lang=EN-US>, Starvation </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보이지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않는다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처음</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생성됐을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=EN-US>priority</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상관없이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모두</span>
            <span lang=KO></span>
            <span lang=EN-US>readyFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하고</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>주기적으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>모든</span>
            <span lang=KO></span>
            <span lang=EN-US>child</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>들을</span>
            <span lang=KO></span>
            <span lang=EN-US>readyFirstQ,
            waitFirstQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=EN-US>push()</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>하여</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기화</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과정을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>거치는</span>
            <span lang=KO></span>
            <span lang=EN-US>MLFQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작동방식</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>덕분이다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>&nbsp;</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>
                <img width=184 height=122 id="그림 10" src="README.fld/image034.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>↑ </span>
            <span lang=EN-US style='font-family:"맑은 고딕",sans-serif'>CFS CPU time</span>
        </p>

        <p class=MsoNormal align=center style='text-align:center'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=EN-US>CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=EN-US>priority</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작은</span>
            <span lang=EN-US>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>높은</span>
            <span lang=EN-US>) child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많은</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU time</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받고</span>
            <span lang=EN-US>,
            priority</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>큰</span>
            <span lang=EN-US>(</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>낮은</span>
            <span lang=EN-US>) child</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>적은</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU time</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할당</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>받은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>알</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>있다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977380">
                <b>
                    <span lang=KO style='font-size:14.0pt;
                    font-family:"맑은 고딕",sans-serif'>느낀</span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:14.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:14.0pt;
                font-family:"맑은 고딕",sans-serif'>점</span>
            </b>
        </h2>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>생각치</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>부분에서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고민을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상황이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자주</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생겼던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제였다</span>
            <span lang=EN-US>.
            IPC</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처음</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사용하다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보니</span>
            <span lang=KO></span>
            <span lang=EN-US>Message Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에서</span>
            <span lang=KO></span>
            <span lang=EN-US>long mtype</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>제외한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>크기를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>매개변수로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>넣어야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>놓쳤던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것과</span>
            <span lang=EN-US>, itimerval</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=EN-US> signal </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>간격에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라</span>
            <span lang=KO></span>
            <span lang=EN-US>OS</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=EN-US>Context
            switching</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의해</span>
            <span lang=KO></span>
            <span lang=EN-US>SIGALRM </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>하나가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>무시되거나</span>
            <span lang=KO></span>
            <span lang=EN-US>Message Queue</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처리하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>도중</span>
            <span lang=KO></span>
            <span lang=EN-US>signal_handler</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>불려지면서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>순서가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>뒤바뀌는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>등의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상황이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생겼었다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>또한</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>디버깅</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>외에도</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>길이와</span>
            <span lang=KO></span>
            <span lang=EN-US>CPU_burst, IO_burst</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>난수</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>범위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>설정에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>따라서도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로그램의</span>
            <span lang=KO></span>
            <span lang=EN-US>Context switching </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과정이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>드물게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어나거나</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>너무</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>자주</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>일어나게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때문에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>적절한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>값을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>찾는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>데에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>오래</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>걸렸다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>스케줄러</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과정에선</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>처음</span>
            <span lang=KO></span>
            <span lang=EN-US>CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이해하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것과</span>
            <span lang=KO></span>
            <span lang=EN-US>MLFQ</span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>적용하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>데에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>제일</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>투자한</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같다</span>
            <span lang=EN-US>. CFS</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가중치와</span>
            <span lang=KO></span>
            <span lang=EN-US>vruntime, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>실제</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>사이의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>관계가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>잘</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이해가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>않아</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생각을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>됐다</span>
            <span lang=EN-US>. MLFQ</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>의</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>경우</span>
            <span lang=EN-US>, 5</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>번</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>규칙을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>때</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>상태인</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>존재해도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>바로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기화하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점형으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현할지</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>아니면</span>
            <span lang=KO></span>
            <span lang=EN-US>Running </span>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>상태인</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>프로세스의</span>
            <span lang=KO></span>
            <span lang=EN-US>Time slice</span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>소진된</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이후에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>우선순위를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>초기화</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>선점형으로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현할지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고민되었지만</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>전자를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>데에는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>오래</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>걸릴</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같아</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>결국</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>후자로</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>되었다</span>
            <span lang=EN-US>.</span>
        </p>

        <p class=MsoNormal style='text-indent:5.0pt'>
            <span lang=KO style='font-family:
            "맑은 고딕",sans-serif'>이전</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제들에</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>비해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>이해해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>구현</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>방법을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생각해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것도</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>많아</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시간을</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>오랫동안</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>투자해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>했던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>과제였다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>아쉬웠던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>점으론</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성하고</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>나서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>살펴보니</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>너무</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>복잡해</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>보인다는</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>생각이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들었다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>좀</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>간단하게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>만들려</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>해도</span>
            <span lang=EN-US>, </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>스케줄러</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성하면서</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>고쳤던</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>버그가</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>다시</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>나타날</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같은</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>느낌이</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>들어</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>결국</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>시도하지</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>못했다</span>
            <span lang=EN-US>. </span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>코드를</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>좀</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>더</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>알아보기</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>쉽게</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>작성하도록</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>노력해야</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>할</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>것</span>
            <span lang=KO></span>
            <span lang=KO style='font-family:"맑은 고딕",sans-serif'>같다</span>
            <span lang=EN-US>.</span>
        </p>

        <span lang=EN-US style='font-size:14.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-indent:7.0pt'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h1>
            <a name="_Toc119977381">
                <b>
                    <span lang=KO style='font-size:24.0pt;
                    font-family:"맑은 고딕",sans-serif'>출력</span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:24.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:24.0pt;
                font-family:"맑은 고딕",sans-serif'>파일</span>
            </b>
        </h1>

        <p class=MsoNormal>
            <span lang=EN-US style='font-size:14.0pt'>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977382">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>FIFO</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 51" src="README.fld/image035.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 52" src="README.fld/image036.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
                <img width=453 height=197 id="그림 77" src="README.fld/image037.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977383">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>RR</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 53" src="README.fld/image038.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 54" src="README.fld/image039.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 55" src="README.fld/image040.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=451 height=304 id="그림 56" src="README.fld/image041.png">
                <img width=453 height=215 id="그림 78" src="README.fld/image042.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977384">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>MLQ</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=401 height=329 id="그림 57" src="README.fld/image043.png">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=400 height=329 id="그림 58" src="README.fld/image044.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=425 height=349 id="그림 59" src="README.fld/image045.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=421 height=346 id="그림 60" src="README.fld/image046.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
                <img width=453 height=269 id="그림 79" src="README.fld/image047.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h2>
            <a name="_Toc119977385">
                <b>
                    <span lang=EN-US style='font-size:14.0pt'>MLFQ</span>
                </b>
            </a>
        </h2>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=358 height=341 id="그림 61" src="README.fld/image048.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=358 height=341 id="그림 70" src="README.fld/image049.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=358 height=340 id="그림 71" src="README.fld/image050.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <p class=MsoNormal align=center style='margin-left:5.0pt;text-align:center;
        text-indent:5.0pt'>
            <span lang=EN-US>
                <img width=358 height=340 id="그림 72" src="README.fld/image051.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
                <img width=453 height=260 id="그림 80" src="README.fld/image052.png" alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            </span>
        </p>

        <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h2>
            <img width=541 height=352 src="README.fld/image053.png" align=left hspace=12 alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            <a name="_Toc119977386"></a>
            <img width=539 height=351 src="README.fld/image054.png" align=left hspace=12 alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            <b>
                <span lang=EN-US style='font-size:
                14.0pt'>CFS</span>
            </b>
        </h2>

        <p class=MsoNormal>
            <img width=542 height=352 src="README.fld/image055.png" align=left hspace=12 alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
            <img width=541 height=352 src="README.fld/image056.png" align=left hspace=12 alt="테이블이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
        </p>

        <p class=MsoNormal>
            <img width=564 height=143 src="README.fld/image057.png" align=left hspace=12 alt="텍스트이(가) 표시된 사진&#10;&#10;자동 생성된 설명">
        </p>

        <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>
            <br clear=all style='page-break-before:always'>
        </span>

        <p class=MsoNormal style='text-autospace:ideograph-numeric ideograph-other;
        word-break:keep-all'>
            <span lang=EN-US>&nbsp;</span>
        </p>

        <h1>
            <a name="_Toc119977387">
                <b>
                    <span lang=KO style='font-size:24.0pt;
                    font-family:"맑은 고딕",sans-serif'>참고</span>
                </b>
            </a>
            <b>
                <span lang=KO style='font-size:24.0pt'></span>
            </b>
            <b>
                <span lang=KO style='font-size:24.0pt;
                font-family:"맑은 고딕",sans-serif'>자료</span>
            </b>
        </h1>

    </div>

    <div>
        <br clear=all>

        <hr align=left size=1 width="33%">

        <div id=edn1>

            <p class=MsoEndnoteText>
                <a href="#_ednref1" name="_edn1" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[i]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>[</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>운영체제</span>
                <span lang=EN-US style='font-size:8.0pt'>] 15. </span>
                <span style='font-size:8.0pt;
                font-family:"맑은 고딕",sans-serif'>선입선처리</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>스케줄링</span>
                <span lang=EN-US style='font-size:8.0pt'>(FIFO </span>
                <span style='font-size:8.0pt;
                font-family:"맑은 고딕",sans-serif'>스케줄링</span>
                <span lang=EN-US style='font-size:
                8.0pt'>) </span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>알고리즘</span>
                <span lang=EN-US style='font-size:8.0pt'> . (2019). https://wonit.tistory.com/103.</span>
            </p>

        </div>

        <div id=edn2>

            <p class=MsoEndnoteText>
                <a href="#_ednref2" name="_edn2" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[ii]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>Scheduling Policy </span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>의</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>발전</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>과정과</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>장단점</span>
                <span lang=EN-US style='font-size:8.0pt'> 1(Round Robin </span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>까지</span>
                <span lang=EN-US style='font-size:8.0pt'>) . (2021).
                https://velog.io/@jewelrykim/Scheduling-Policy-</span>
                <span style='font-size:
                8.0pt;font-family:"맑은 고딕",sans-serif'>의</span>
                <span lang=EN-US style='font-size:8.0pt'>-</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>발전</span>
                <span lang=EN-US style='font-size:8.0pt'>-</span>
                <span style='font-size:8.0pt;
                font-family:"맑은 고딕",sans-serif'>과정과</span>
                <span lang=EN-US style='font-size:
                8.0pt'>-</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>장단점</span>
                <span lang=EN-US style='font-size:8.0pt'>-1Round-Robin-</span>
                <span style='font-size:
                8.0pt;font-family:"맑은 고딕",sans-serif'>까지</span>
                <span lang=EN-US style='font-size:8.0pt'>.</span>
            </p>

        </div>

        <div id=edn3>

            <p class=MsoEndnoteText>
                <a href="#_ednref3" name="_edn3" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[iii]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>[</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>운영체제</span>
                <span lang=EN-US style='font-size:8.0pt'>] MLQ &amp; MFQ . (2019).
                http://itnovice1.blogspot.com/2019/08/multi-level-queue.html.</span>
            </p>

        </div>

        <div id=edn4>

            <p class=MsoEndnoteText>
                <a href="#_ednref4" name="_edn4" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[iv]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>[</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>운영체제</span>
                <span lang=EN-US style='font-size:8.0pt'>] MLQ &amp; MFQ . (2019).
                http://itnovice1.blogspot.com/2019/08/multi-level-queue.html.</span>
            </p>

        </div>

        <div id=edn5>

            <p class=MsoEndnoteText>
                <a href="#_ednref5" name="_edn5" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[v]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>/kernel/sched/core.c
                . (n.d.). https://elixir.bootlin.com/linux/latest/source/kernel/sched/core.c#L11202.</span>
            </p>

        </div>

        <div id=edn6>

            <p class=MsoEndnoteText>
                <a href="#_ednref6" name="_edn6" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[vi]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>[</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>리눅스커널</span>
                <span lang=EN-US style='font-size:8.0pt'>] </span>
                <span style='font-size:8.0pt;
                font-family:"맑은 고딕",sans-serif'>스케줄링</span>
                <span lang=EN-US style='font-size:
                8.0pt'>: CFS </span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>스케줄러</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>알고리즘과</span>
                <span lang=EN-US style='font-size:8.0pt'> vruntime . (2019).
                http://rousalome.egloos.com/10002542.</span>
            </p>

        </div>

        <div id=edn7>

            <p class=MsoEndnoteText>
                <a href="#_ednref7" name="_edn7" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[vii]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>개념정리</span>
                <span lang=EN-US style='font-size:8.0pt'> . (2010). https://se.uzoogom.com/186.</span>
            </p>

        </div>

        <div id=edn8>

            <p class=MsoEndnoteText>
                <a href="#_ednref8" name="_edn8" title="">
                    <span class=MsoEndnoteReference>
                        <span lang=EN-US>
                            <span class=MsoEndnoteReference>
                                <span lang=EN-US style='font-size:10.0pt;font-family:"Calibri",sans-serif'>[viii]</span>
                            </span>
                        </span>
                    </span>
                </a>
                <span lang=EN-US></span>
                <span lang=EN-US style='font-size:8.0pt'>[</span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>리눅스커널</span>
                <span lang=EN-US style='font-size:8.0pt'>] </span>
                <span style='font-size:8.0pt;
                font-family:"맑은 고딕",sans-serif'>스케줄링</span>
                <span lang=EN-US style='font-size:
                8.0pt'>: CFS </span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>스케줄러</span>
                <span style='font-size:8.0pt'></span>
                <span style='font-size:8.0pt;font-family:"맑은 고딕",sans-serif'>알고리즘과</span>
                <span lang=EN-US style='font-size:8.0pt'> vruntime . (2019).
                http://rousalome.egloos.com/10002542.</span>
            </p>

        </div>

    </div>

</html>
