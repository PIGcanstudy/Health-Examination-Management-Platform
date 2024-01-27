<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-27 17:50:21
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-27 19:06:06
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\healthcheck\MedicalExaminer\components\test.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <div class="uploadDialog">
    <el-dialog v-model="dialogVisible" title="人员批量导入" width="50%" style="justify-content: left">
      <div class="model-body" style="flex-direction: column">
        <el-upload style="border: 1px solid #c3c3c3" multiple>
          <div class="el-upload__text" style="width: 800px; height: 150px; display: flex; justify-content: center; align-items: center">
            <el-icon style="display: flex; justify-content: center; align-items: center" class="el-icon--upload"><UploadFilled /></el-icon>

            请选择需要上传的文件
          </div>
        </el-upload>
        <p>提示；</p>
        <p>1.请按模板填写数据，模板格式禁止调整</p>
        <p>2.导入会覆盖之前数据（请慎重操作）</p>
        <p>3.上传文件类型只能为"xls", "xlsx", "xlsm"</p>
      </div>
      <template #footer>
        <span class="dialog-footer">
          <el-upload>
            <el-button style="background-color: #2db7f5; border-color: #2db7f5; color: #fff; margin-right: 12px"> 模板下载</el-button>
          </el-upload>
          <el-button type="primary" style="margin-bottom: 10px" @click="dialogVisible = false"> 关闭 </el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const dialogVisible = ref(false)
</script>
