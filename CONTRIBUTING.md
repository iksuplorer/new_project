### RockstarQueen
<RockstarQueen>
<p>
 ClassDiagram 그리기 ver.1 (2020/11/03)<br>
 CMrJackInLondonDlg의 버튼 그래픽 적용 (2020/11/10)<br>
 CMrJackInLondonInGame_T 수정 (2020/11/10)<br>
 CMrJackInLondonDlg 수정 (2020/11/10)<br>
 Tile Class 구현 (2020/11/16)<br>
 CMrJackInLondonInGame의 버튼 그래픽 적용(2020/11/17)<br>
 Resource 경로 정리 및 디버그(2020/11/17)<br>
 그래픽 Testing (2020/11/23)<br>
 Character Class 및 sub Classes 추가(2020/11/23)<br>
 그래픽 최초 좌표 찾기(2020/11/23)<br>
</p>
  
### hyunwoo9120
<hyunwoo9120>
<p>
구현 할 클래스와 메소드 의사코드 작성<br>
서버-클라이언트의 통신 프로토콜 결정(TCP)<br>
ListenSocket과 ClientSocket Class 추가(2020/11/14)<br>
ClientSocket에서 소켓 생성 후 Server에 접속 요청(2020/11/15)<br>
서버와 클라이언트의 동작 방식을 시각자료로 제작(2020/11/19)<br>
2인 통신 프로토타입(채팅) 제작 (2020/11/20)<br>
multi room 구조(thread)로 2인 통신 제작 (2020/11/21)<br>
주고 받을 데이터(gaemdata) 재정의 (2020/12/6)
받은 gamedata를 파일로 저장<br>
서버에서 gamedata를 확인하여 라운드에 따라 다르게 동작<br>
mfc 안에서<br>
 - 서버에서 받은 gamedata를 자체 사용 데이터에 넣기<br>
 - 서버에 데이터를 보내기 전에 자체 데이터를 gamedata에 넣기<br>
 - gamedata에서 유저 차례를 확인하여 내 차례가 아니면 데이터 recv<br>
 - turn end 버튼 클릭 시 라운드, 턴 정보를 갱신하여 gamedata에 넣기<br>
 - turn end 버튼 클릭 시 서버에 gamedata 전달하고 받기<br>
<br>자세한 사항은 링크에서 
https://github.com/hyunwoo9120/mrJackServer.git
</p>

  
### andylhw
<andylhw>
<p>
  MrJackInLondonInGame_T, MrJackInLondonHTP 파일 추가<br>
  MrJackInLondonDlg에 버튼 생성 후 뒤 두 대화상자랑 연결 기능 추가(2020/11/08)<br>
  MrJackInLondonDlg 파일의 해상도 조정(min, max조정 고민중)(2020/11/08)<br>
  MrJackInLondonInGame 내부 맵 비트맵 파일 생성해서 넣음.(2020/11/09)<br>
  MrJackInLondon How to play 구현. pdf파일을 열리게 함(엣지 익스플로러) (2020/11/14)<br>
  MrJackInLondon InGame에 도움말 버튼 추가, 클릭시 HTP.pdf 구동(2020/11/14)<br>
  MrJackInLondon pdf방식 철회. HTP Dialog 작성 시작함(2020/11/17)<br>
  MrJackInLondonHTP에 있는 버튼 동작 구현, Invalidate를 통한 새로고침 구현(2020/11/17)<br>
  MrJackInLondonInGame에서 png파일 추가 확인(2020/11/20)<br>
  MrJackInLondonInGame에서 함수 내 사각형 클릭 구현 기능 추가(2020/11/20)<br>
  MrJackInLondonInGame에서 타일 사각형 추가 & 출구 사각형 추가 + 충돌판정 구현(2020/11/20)<br>
  MrJackInLondonInGame에서 좌표 구현(2020/11/25)<br>
  MrJackInLondonInGame에서 말 움직이는거 구현(2020/11/25)<br>
  MrJackInLondonInGame에서 Character Class 다듬기(2020/11/25)<br>
  Added Move HTP bmp file(2020/11/25)<br>
  Tile Class Added(2020/11/28)<br>
  Character Class Added(2020/11/28)<br>
  Linked Character Class&Tile class to InGmae(2020/11/28)<br>
  게임 내부 구현중.. 캐릭터 자체이동 가능.(2020/11/29)<br>
  Movecount 추가 완료. 캐릭터는 일정 횟수 이상 한 턴에 못움직임(2020/11/29)<br>
  Watson 구현완료. 게임에 추가됨.(2020/11/30)<br>
  Game시작시 역할에 따라 잭이 누구인지 알려주는 기능 추가(2020/11/30)<br>
  Game 내부 타일 이동 절반이상 구현 (assisted by. 길다영)(2020/12/01)<br>
  Game Map 이동 구현 완료 (맨홀 제외&스텔시 제외)(2020/12/01)<br>
  Round End 버튼 동작 설계(2020/12/02)<br>
  Round End시, 시민을 확정하게 하는 코드 추가(2020/12/02)<br>
  확정시민일때, 이미지가 바뀌게 하는 현상 추가(2020/12/02)<br>
  가로등&Watson으로 onLight함수 동작 & 캐릭터가 on&off light상태 확인가능(2020/12/02)<br>
  마이너 버그 수정(watson.lightpos==0일때 동작, 가로등 꺼진 상태에서 동작하던거 수정) (2020/12/04~05)<br>
  가로등&맨홀&검문소 기능 구현 완료(2020/12/05)<br>
  잭이 탈출할 때, 조건 구현 완료(2020/12/05)<br>
  turnend 버튼 누를 시, movecount 초기화 구현 완료(2020/12/05)<br>
  캐릭터가 맵 중 일부를 이동할수 없는 현상 수정(2020/12/05)<br>
  캐릭터가 겹칠 때, 이동가능하게 하는 현상 수정(2020/12/05)<br>
  자잘한 버그 수정 - 맨홀 하나 구현 안된것 수정&게임 종료조건 주석처리로 추가(2020/12/06)<br>
  자잘한 버그 수정 - 94번타일 이동 불가 수정.(2020/12/08)<br>
</p>
  
### arittung
<arittung>
<p>
 게임에 필요한 이미지 편집 및 제작(2020/11/10)<br>
  (1) 버튼 4개(Click전 후의 Play와 Rule)<br>
  (2) 가로등 5개(1~4라운드 임시 가로등과 영구 가로등)<br> 
  (3) 맨홀 <br>
  (4) 라운드<br>
  (5) 캐릭터카드 8종<br>
  (6) 범인 카드 8종<br>
 게임에 필요한 이미지 편집 및 제작(2020/11/15)<br>
  (1) 버튼 4개(Click전 후의 Turn End, 톱니바퀴 모양의 설정 버튼)<br>
 RoomList Class(전체 방 관리하는 클래스), Game Class 구현. (2020/11/15)<br>
 게임에 필요한 이미지 편집 및 제작(2020/11/16)<br>
  (1) 로딩 gif<br>
  (2) 육각형 테두리(타일 클릭시 유저에게 클릭한 타일임을 알려주는 리소스)<br>
 서버-클라이언트 보조(2020/11/20)<br>
 게임에 필요한 이미지 편집 및 제작(2020/11/23)<br>
  (1) 가로등(5개), 맨홀(1개), 캐릭터 말(16개) 생성된 게임판에 맞춰 사이즈 조절
  (2) 가로등이 비추는 곳 나타내는 반투명 육각형 생성<br>
  Game 내부 타일 이동 절반이상 구현보조(2020/12/01)<br>
  게임에 필요한 이미지 편집 및 제작(2020/12/05)<br>
  (1) 버튼 2개(Click전 후의 Move End 버튼)<br>
  게임에 필요한 이미지 편집 및 제작(2020/12/07)<br>
  (1) 노란 블록 이미지<br>
  최종 보고서 작성(2020/12/08)<br>
  readme 작성(2020/12/08)<br>
</p>
