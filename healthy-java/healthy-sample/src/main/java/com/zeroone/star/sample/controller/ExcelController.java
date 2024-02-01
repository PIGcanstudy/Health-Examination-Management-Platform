package com.zeroone.star.sample.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sample.test.entity.User;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：演示Excel报表下载
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Controller
@RequestMapping("excel")
@Api(tags = "excel")
public class ExcelController {
    private List<User> datas = new ArrayList<>();
    @Resource
    EasyExcelComponent excel;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @PostConstruct
    public void initData() {
        for (int i = 1; i <= 50; ++i) {
            User user = new User();
            user.setId(i);
            user.setName("测试导出" + i);
            user.setPhone("1380000000" + i);
            datas.add(user);
        }
    }

    @GetMapping(value = "download", produces = "application/octet-stream")
    @ApiOperation(value = "下载报表")
    public ResponseEntity<byte[]> download() throws Exception {
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试表单", out, User.class, datas);
        // 响应给前端
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> res = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return res;
    }

    /**
     * 导出到文件服务器
     * @return JsonVO<String>
     * @throws Exception e
     */
    @GetMapping(value = "export-todfs")
    @ApiOperation("导出到文件服务器")
    @ResponseBody
    public JsonVO<String> exportToFileServer() throws Exception {
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试表单", out, User.class, datas);
        out.close();
        // 上传到文件服务器
        FastDfsFileInfo xlsx = dfs.uploadFile(out.toByteArray(), ".xlsx");
        if (xlsx != null) {
            return JsonVO.success(dfs.fetchUrl(xlsx, fileServerUrl, true));
        }
        return JsonVO.fail(null);
    }
}
