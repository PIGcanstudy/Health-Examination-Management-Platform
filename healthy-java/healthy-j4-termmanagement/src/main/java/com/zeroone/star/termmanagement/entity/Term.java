package com.zeroone.star.termmanagement.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * @author 刘静
 * 时间：2024.1.1
 * 功能：
 */
@Data
public class Term implements Serializable {

    private String name;
    private String medicalType;
    private String termType;
    private String hazardFactor;
    private String jobStatus;
    private String status;
    private String termContent;
    private Date createTime;
    private String operation;
}
