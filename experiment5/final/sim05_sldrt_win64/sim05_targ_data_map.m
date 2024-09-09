  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (sim05_P)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% sim05_P.AnalogOutput_FinalValue
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% sim05_P.AnalogOutput_InitialValue
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% sim05_P.EncoderInput_InputFilter
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% sim05_P.EncoderInput1_InputFilter
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% sim05_P.EncoderInput_MaxMissedTicks
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% sim05_P.EncoderInput1_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% sim05_P.AnalogOutput_MaxMissedTicks
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% sim05_P.EncoderInput_YieldWhenWaiting
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% sim05_P.EncoderInput1_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% sim05_P.AnalogOutput_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% sim05_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% sim05_P.EncoderInput1_Channels
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% sim05_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% sim05_P.AnalogOutput_RangeMode
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% sim05_P.AnalogOutput_VoltRange
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% sim05_P.Gain2_Gain
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% sim05_P.Constant4_Value
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% sim05_P.Constant3_Value
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% sim05_P.Constant2_Value
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% sim05_P.TransferFcn_A
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
	  ;% sim05_P.TransferFcn_C
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 6;
	
	  ;% sim05_P.Internal_A
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 8;
	
	  ;% sim05_P.Internal_B
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 11;
	
	  ;% sim05_P.Internal_C
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 12;
	
	  ;% sim05_P.Internal_InitialCondition
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 14;
	
	  ;% sim05_P.Onoff_Gain
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 15;
	
	  ;% sim05_P.GainArm_Gain
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 16;
	
	  ;% sim05_P.Gain1_Gain
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 17;
	
	  ;% sim05_P.TransferFcn1_A
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 18;
	
	  ;% sim05_P.TransferFcn1_C
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 20;
	
	  ;% sim05_P.TransferFcn1_D
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 22;
	
	  ;% sim05_P.TransferFcn4_A
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 23;
	
	  ;% sim05_P.TransferFcn4_C
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 25;
	
	  ;% sim05_P.TransferFcn4_D
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 27;
	
	  ;% sim05_P.Constant1_Value
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 28;
	
	  ;% sim05_P.Saturation_UpperSat
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 29;
	
	  ;% sim05_P.Saturation_LowerSat
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 30;
	
	  ;% sim05_P.Gain_Gain
	  section.data(23).logicalSrcIdx = 37;
	  section.data(23).dtTransOffset = 31;
	
	  ;% sim05_P.Constant_Value
	  section.data(24).logicalSrcIdx = 38;
	  section.data(24).dtTransOffset = 32;
	
	  ;% sim05_P.GainPendulum_Gain
	  section.data(25).logicalSrcIdx = 39;
	  section.data(25).dtTransOffset = 33;
	
	  ;% sim05_P.Constant5_Value
	  section.data(26).logicalSrcIdx = 40;
	  section.data(26).dtTransOffset = 34;
	
	  ;% sim05_P.Constant6_Value
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (sim05_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% sim05_B.Onoff
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% sim05_B.Sum1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% sim05_B.GainArm
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% sim05_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% sim05_B.Sum2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% sim05_B.DataTypeConversion
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% sim05_B.Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% sim05_B.Constant
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% sim05_B.GainPendulum
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% sim05_B.Sum4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (sim05_DW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% sim05_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% sim05_DW.EncoderInput1_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% sim05_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% sim05_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% sim05_DW.delta_yr_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% sim05_DW.scope2_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% sim05_DW.theta_deg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% sim05_DW.u_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% sim05_DW.ydeg_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1516413014;
  targMap.checksum1 = 4001749507;
  targMap.checksum2 = 1072173849;
  targMap.checksum3 = 2883279561;

