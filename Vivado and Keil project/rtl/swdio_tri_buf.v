module swdio_tri_buf (
    input  swd_o,
    output swd_i,
    input  swd_oe,

    inout swd_io
);

  //ԭ��
  IOBUF swd_iobuf_inst (
      .O (swd_i),
      .I (swd_o),
      .IO(swd_io),

      .T(~swd_oe)  //T=1��Ƭ�⵽Ƭ�ڣ�0��Ƭ�ڵ�Ƭ��
  );

endmodule
